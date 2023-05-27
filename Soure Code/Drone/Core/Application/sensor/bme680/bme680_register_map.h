/*
 * bme680_register_map.h
 *
 *  Created on: Mar 28, 2023
 *      Author: nguye
 */

#include "bme680_def.h"

#ifndef CORE_APPLICATION_SENSOR_BME680_BME680_REGISTER_MAP_H_
#define CORE_APPLICATION_SENSOR_BME680_BME680_REGISTER_MAP_H_

#ifndef	BME680_I2C
enum bme680_register_i2c{
	/* Register for 3rd group of coefficients */
	BME68X_REG_COEFF3 		= 0x00,
	/* 0th Field address*/
	MEAS_STATUS_0			= 0x1D,
	PRESS_MSB				= 0x1F,
	PRESS_LSB				= 0x20,
	PRESS_XLSB				= 0x21,
	TEMP_MSB				= 0x22,
	TEMP_LSB				= 0x23,
	TEMP_XLSB				= 0x24,
	HUM_MSB					= 0x25,
	HUM_LSB					= 0x26,
	GAS_R_MSB				= 0x2A,
	GAS_R_LSB				= 0x2B,
	IDAC_HEAT_0				= 0x50,
	IDAC_HEAT_1				= 0x51,
	IDAC_HEAT_2				= 0x52,
	IDAC_HEAT_3				= 0x53,
	IDAC_HEAT_4				= 0x54,
	IDAC_HEAT_5				= 0x55,
	IDAC_HEAT_6				= 0x56,
	IDAC_HEAT_7				= 0x57,
	IDAC_HEAT_8				= 0x58,
	IDAC_HEAT_9				= 0x59,
	RES_HEAT_0				= 0x5A,
	RES_HEAT_1				= 0x5B,
	RES_HEAT_2				= 0x5C,
	RES_HEAT_3				= 0x5D,
	RES_HEAT_4				= 0x5E,
	RES_HEAT_5				= 0x5F,
	RES_HEAT_6				= 0x60,
	RES_HEAT_7				= 0x61,
	RES_HEAT_8				= 0x62,
	RES_HEAT_9				= 0x63,
	GAS_WAIT_0				= 0x64,
	GAS_WAIT_1				= 0x65,
	GAS_WAIT_2				= 0x66,
	GAS_WAIT_3				= 0x67,
	GAS_WAIT_4				= 0x68,
	GAS_WAIT_5				= 0x69,
	GAS_WAIT_6				= 0x6A,
	GAS_WAIT_7				= 0x6B,
	GAS_WAIT_8				= 0x6C,
	GAS_WAIT_9				= 0x6D,
	CTRL_GAS_0				= 0x70,
	CTRL_GAS_1				= 0x71,
	CTRL_HUM				= 0x72,
	STATUS 					= 0x73,
	BME680_REG_CTRL_MEAS	= 0x74,
	BME680_REG_CONFIG		= 0x75,
};
#endif

enum bme680_register_page{
	BME680_ID			= 0xD0,
	BME680_RESET		= 0xE0,
};

#endif /* CORE_APPLICATION_SENSOR_BME680_BME680_REGISTER_MAP_H_ */
