/*
 * app_bluenrg.c
 *
 *  Created on: 26 Mar 2022
 *      Author: Juan Gomez
 */

#include <stdio.h>
#include "bluenrg_conf.h"
#include "hci.h"
#include "bluenrg1_types.h"
#include "bluenrg1_gap.h"
#include "bluenrg1_aci.h"
#include "bluenrg1_hci_le.h"
#include "service.h"

#include "app_bluenrg.h"

#define BDADDR_SIZE		6

uint8_t  SERVER_BDARR[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};

void bluenrg_init(void){

	tBleStatus ret;
	uint8_t bdaddr[BDADDR_SIZE];
	const char *name = "Juan";
	uint16_t service_handle, dev_name_char_handle, appearance_char_habdle;

	BLUENRG_memcpy(bdaddr, SERVER_BDARR, sizeof(SERVER_BDARR));

	// Initialize HCI
	hci_init(APP_UserEvRx, NULL);
	//Reset HCI
	hci_reset();
	HAL_Delay(100);
	//Configure device address
	ret = aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET, CONFIG_DATA_PUBADDR_LEN, bdaddr);
	if(ret != BLE_STATUS_SUCCESS){
		printf("aci_hal_write_config_data : FAILED \n\r");
	}
	//Initialize GATT server
	ret = aci_gatt_init();
	if(ret != BLE_STATUS_SUCCESS){
		printf("aci_gatt_init : FAILED \n\r");
	}
	//Initialize GAP service
	ret = aci_gap_init(GAP_PERIPHERAL_ROLE, 0, 0x07,  &service_handle, &dev_name_char_handle, &appearance_char_habdle);
	if(ret != BLE_STATUS_SUCCESS){
		printf("aci_gap_init : FAILED \n\r");
	}
	//Update device name characteristic
	aci_gatt_update_char_value(&service_handle, &dev_name_char_handle, 0, strlen(name), (uint8_t*)name);
	//Add custom service
	ret = add_siemple_service();
	if(ret != BLE_STATUS_SUCCESS){
		printf("add_siemple_service : FAILED \n\r");
	}
}

uint8_t btn_state;

void bluenrg_process(void){

	tBleStatus ret;

	uint8_t local_name[] = {AD_TYPE_COMPLETE_LOCAL_NAME, 'B', 'L','E', '-', 'J', 'U', 'A', 'N'};

	//Set device in General Discoverable Mode
	ret = aci_gap_set_discoverable(ADV_IND, 0, 0, PUBLIC_ADDR, NO_WHITE_LIST_USE, sizeof(local_name), local_name, 0, NULL, 0, 0);
	if(ret != BLE_STATUS_SUCCESS){
		printf("aci_gap_set_discoverable : FAILED \n\r");
	}

	//process user event
	hci_user_evt_proc();

	//get button state
	btn_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if(btn_state == 0){

		uint8_t data[2] = {'a', 'a'};
		send_data(data, sizeof(data));
	}
}







