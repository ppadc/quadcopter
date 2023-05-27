/*
 * bme680.c
 *
 *  Created on: Mar 28, 2023
 *      Author: nguye
 */

#include "bme680_register_map.h"
#include <string.h>
#include <i2c.h>
#include "user_define.h"
#include "bme680.h"
#include "bme680_def.h"

static int bme680_read(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Read(&BME680_I2C, BME680_I2C_ADDR, addr , I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS)!= HAL_OK){
		*value = 0;
		return -1;
	}
	return 0;
}

static int bme680_write(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Write(&BME680_I2C, BME680_I2C_ADDR, addr , I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS)!= HAL_OK)
		return -1;
	return 0;
}

static int bme680_read_bytes(uint8_t addr, uint8_t *value, uint8_t len){
	if(HAL_I2C_Mem_Read(&BME680_I2C, BME680_I2C_ADDR, addr , I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS)!= HAL_OK){
		memset(value,0,len);
		return -1;
	}
	return 0;
}

/* User use when need I2C write Byes function */
//static int bme680_write_bye(uint8_t addr, uint8_t *value, uint8_t len){
//	if(HAL_I2C_Mem_Write(&BME680_I2C, BME680_I2C_ADDR, addr , I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS)!= HAL_OK)
//		return -1;
//	return 0;
//}

int bme680_init(){
	uint8_t tmp;
	tmp = 0x00;
}
