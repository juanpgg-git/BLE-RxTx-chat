/*
 * service.c
 *
 *  Created on: 26 Mar 2022
 *      Author: Juan Gomez
 */
#include <stdio.h>
#include <stdlib.h>
#include "bluenrg1_gap.h"
#include "bluenrg1_gatt_aci.h"
#include "service.h"

//custom UUID service
uint8_t SERVICE_UUID[16] = 	{0x66, 0x9a, 0x0c, 0x20, 0x00, 0x08, 0x96, 0x9e, 0xe2, 0x11, 0x9e, 0xb1, 0xe0, 0xf2, 0x73, 0xd9};
uint8_t CHAR_UUID_TX[16] = 	{0x66, 0x9a, 0x0c, 0x20, 0x00, 0x08, 0x96, 0x9e, 0xe2, 0x11, 0x9e, 0xb1, 0xe1, 0xf2, 0x73, 0xd9};
uint8_t CHAR_UUID_RX[16] = {0x66, 0x9a, 0x0c, 0x20, 0x00, 0x08, 0x96, 0x9e, 0xe2, 0x11, 0x9e, 0xb1, 0xe2, 0xf2, 0x73, 0xd9};

uint16_t chat_service_handle, tx_char_handle, rx_char_handle;

uint8_t connected = 0;
uint8_t set_connectable = 1;
uint16_t connection_handle = 0;
uint8_t notification_enabled = 0;

tBleStatus add_siemple_service(void){

	tBleStatus ret;
	Service_UUID_t service_uuid;
	Char_UUID_t char_uuid_tx, char_uuid_rx;

	BLUENRG_memcpy(service_uuid.Service_UUID_128, SERVICE_UUID, 16);
	BLUENRG_memcpy(char_uuid_tx.Char_UUID_128, CHAR_UUID_TX, 16);
	BLUENRG_memcpy(char_uuid_rx.Char_UUID_128, CHAR_UUID_RX, 16);

	//add service
	ret = aci_gatt_add_service(UUID_TYPE_128, &service_uuid, PRIMARY_SERVICE, 7, &chat_service_handle);

	// add characteristic
	ret = aci_gatt_add_char(chat_service_handle, UUID_TYPE_128, &char_uuid_tx, 20,
											CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE,
											0, 0, 1, &tx_char_handle);

	ret = aci_gatt_add_char(chat_service_handle, UUID_TYPE_128, &char_uuid_rx, 20,
											CHAR_PROP_WRITE | CHAR_PROP_WRITE_WITHOUT_RESP, ATTR_PERMISSION_NONE,
											GATT_NOTIFY_ATTRIBUTE_WRITE, 0, 1, &rx_char_handle);

	return ret;
}

uint8_t rcv_data[20];

void receive_data(uint8_t * data_buffer, uint8_t no_bytes){

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	for(int i = 0;  i < no_bytes; i++){

		rcv_data[i] = data_buffer[i];
	}
}

void send_data(uint8_t * data_buffer, uint8_t no_bytes){

	tBleStatus ret;

	//update characteristic value
	ret = aci_gatt_update_char_value(chat_service_handle, tx_char_handle, 0, no_bytes, (uint8_t*)&data_buffer);
	if(ret != BLE_STATUS_SUCCESS){
		printf("aci_gatt_update_char_value : FAILED \n\r");
	}
}

void Attribute_Modified_CB(uint16_t handle, uint8_t data_length, uint8_t * att_data){

	if(handle == rx_char_handle + 1){

		receive_data(att_data, data_length);
	}
	/*
	 * for enabling notifications, the configuration data is [0x00, 0x01]. in this case the handle of the attribute
	 * "TX characteristic is offset by two from the characteristic handle
	 */
	else if(handle == tx_char_handle + 2){

		if(att_data[0]  == 0x01){

			notification_enabled = 1;
		}
	}
}

void aci_gatt_attribute_modified_event(uint16_t Connection_handle, uint16_t Attr_Handle, uint16_t Offset,
		uint16_t Attr_Data_Length, uint8_t Attr_Data[]){

	Attribute_Modified_CB(Attr_Handle, Attr_Data_Length, Attr_Data);
}

void aci_gatt_notification_event(uint16_t Connection_Handle, uint16_t Attribute_Handle,
														uint8_t Attribute_Value_Length, uint8_t Attribute_Value[]){

	if(Attribute_Handle == tx_char_handle + 2){

		receive_data(Attribute_Value, Attribute_Value_Length);
	}
}


void hci_le_connection_complete_event(uint8_t Status, uint16_t Connection_Handle, uint8_t Role, uint8_t Peer_Address_Type,
																	uint8_t Peer_Address[6], uint16_t Conn_Interval, uint16_t Conn_Latency,
																	uint16_t Supervision_Timeout, uint8_t Master_Clock_Accuracy)
{
	connected = 1;
	connection_handle = Connection_Handle;
}

void hci_disconnection_complete_event(uint8_t Status, uint16_t Connection_Handle, uint8_t Reason){

	connected = 1;
	set_connectable = 1;
	connection_handle = 0;

	printf("Disconnected \n\r");
}

void APP_UserEvRx(void *pData){

	uint32_t i;

	hci_spi_pckt *hci_pckt = (hci_spi_pckt*)pData;

	//process event packet
	if(hci_pckt->type == HCI_EVENT_PKT){

		//Get data from packet
		hci_event_pckt *event_pckt = (hci_event_pckt*)hci_pckt->data;

		//process meta data
		if(event_pckt->evt == EVT_LE_META_EVENT){

			//get meta data
			evt_le_meta_event *evt = (void*)event_pckt->data;

			//process each meta data event
			for(i = 0; i < (sizeof(hci_le_meta_events_table) / sizeof(hci_le_meta_events_table_type)); i++){

				if(evt->subevent == hci_le_meta_events_table[i].evt_code){

					hci_le_meta_events_table[i].process((void*)evt->data);
				}
			}
		}

		//process vendor event
		else if(event_pckt->evt == EVT_VENDOR){

			//get meta data
			evt_blue_aci *blue_evt = (void*)event_pckt->data;

			//process each vendor event
			for(i = 0; i < (sizeof(hci_vendor_specific_events_table) / sizeof(hci_vendor_specific_events_table_type)); i++){

				if(blue_evt->ecode == hci_vendor_specific_events_table[i].evt_code){

					hci_vendor_specific_events_table[i].process((void*)blue_evt->data);
				}
			}
		}

		//process other events
		else{

			for(i = 0; i < (sizeof(hci_events_table) / sizeof(hci_events_table_type)); i++){

				if(event_pckt->evt == hci_events_table[i].evt_code){

					hci_events_table[i].process((void*)event_pckt->data);
				}
			}
		}
	}
}












