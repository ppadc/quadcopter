/*
 * main.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: gvargas
 */

#include "main.h"
#include "HM11.h"
#include "BNO055.h"
#include "NRF24L01.h"
extern "C" {
	void log_i(char *data, ...);
	I2C_HandleTypeDef hi2c1;
	SPI_HandleTypeDef hspi1;
}

HM11 phone;

BNO055 gyro(&hi2c1);

void rxChar(char c){

	phone.addCharacter(c);

}


uint8_t data[22];
void maincpp(){
	gyro.reset();
	gyro.enableNDOF();

	NRF24L01 nrf(&hspi1, CSN_GPIO_Port, CE_GPIO_Port,CSN_Pin,CE_Pin);
	nrf.config();

	nrf.modeTX();

	char msg[32];

	double roll = 0.0;

	sprintf(msg,"45.0");
	msg[30] = 'R';
	msg[31] = 'O';
	nrf.sendMessage(msg,20);
	HAL_Delay(600);

	sprintf(msg,"0.0");
	msg[30] = 'R';
	msg[31] = 'O';
	nrf.sendMessage(msg,20);
	HAL_Delay(600);

	sprintf(msg,"-45.0");
	msg[30] = 'R';
	msg[31] = 'O';
	nrf.sendMessage(msg,20);
	HAL_Delay(600);

	sprintf(msg,"0.0");
	msg[30] = 'R';
	msg[31] = 'O';
	nrf.sendMessage(msg,20);
	HAL_Delay(600);


	while(1){

		gyro.getData();


		//log_i("R:%.2f\r",gyro.roll);

		 roll = gyro.pitch;
		 if(gyro.usePitchInsteadOfRoll == 0)
			 roll = gyro.roll;


		 if( roll > (float)gyro.maxServoRoll ) roll = (float)gyro.maxServoRoll ;
		 if( roll < -(float)gyro.maxServoRoll ) roll = -(float)gyro.maxServoRoll ;
//		 if( roll < -58 ) roll = -58.0;
		  sprintf(msg,"%.2f",roll);
		        msg[30] = 'R';
		        msg[31] = 'O';

		        nrf.sendMessage(msg);

		        HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);

		itoa(gyro.SysTrig,msg,2);

		log_i("mr:%d\rsr:%.2f\rClk:%8s\rH:%.2f\rR:%.2f\rP:%.2f\rC:%d\rCm:%d\rCa:%d\rCg:%d\rCs:%d\rCF:%d\rou:%s\r",gyro.maxServoRoll,roll,msg, gyro.heading, gyro.roll,gyro.pitch,gyro.calibrationData,gyro.calMag,gyro.calAcc,gyro.calGyr,gyro.calSys,gyro.calibrate,gyro.getOrientationText());
		if( phone.newMessage == 1){
			HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
			phone.parseCommand();

			if( strcmp(phone.field,"Calibrate") == 0 ){
				gyro.calibrate = phone.value;
			}
			if( strcmp(phone.field, "Roll") == 0) {
				gyro.saveOrientationAsPitch(0);
			}
			if( strcmp(phone.field, "Pitch") == 0) {
				gyro.saveOrientationAsPitch(1);
			}
			if( strcmp(phone.field, "MaxRoll") == 0) {
				gyro.saveMaxServoRoll(phone.value);
			}
			HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
		}
	}
}



