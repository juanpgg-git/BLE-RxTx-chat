/*
 * service.h
 *
 *  Created on: 26 Mar 2022
 *      Author: Juan Gomez
 */

#ifndef INC_SERVICE_H_
#define INC_SERVICE_H_

tBleStatus add_siemple_service(void);
void APP_UserEvRx(void *pData);
void send_data(uint8_t * data_buffer, uint8_t no_bytes);

#endif /* INC_SERVICE_H_ */
