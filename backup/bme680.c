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
void bme680_oversampling_humidity(bme680_variant_id_macro oversampling);
void bme680_oversampling_temperature(bme680_variant_id_macro oversampling);
void bme680_oversampling_pressure(bme680_variant_id_macro oversampling);

void bme680_oversampling_humidity(bme680_variant_id_macro oversampling){
	uint8_t tmp;
	switch(oversampling){
	case BME680_OS_NONE:
			tmp = BME680_OS_NONE;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	case BME680_OS_1X:
			tmp = BME680_OS_1X;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	case BME680_OS_2X:
			tmp = BME680_OS_2X;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	case BME680_OS_4X:
			tmp = BME680_OS_4X;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	case BME680_OS_8X:
			tmp = BME680_OS_8X;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	case BME680_OS_16X:
			tmp = BME680_OS_16X;
			bme680_write(BME680_REG_CTRL_HUM,&tmp);
	break;
	}
}

void bme680_oversampling_temperature(bme680_variant_id_macro oversampling){
	uint8_t tmp;
	switch(oversampling){
	case BME680_OS_NONE:
			tmp = BME680_OS_NONE<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_1X:
			tmp = BME680_OS_1X<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_2X:
			tmp = BME680_OS_2X<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_4X:
			tmp = BME680_OS_4X<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_8X:
			tmp = BME680_OS_8X<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_16X:
			tmp = BME680_OS_16X<<5;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	}
}

void bme680_oversampling_pressure(bme680_variant_id_macro oversampling){
	uint8_t tmp;
	switch(oversampling){
	case BME680_OS_NONE:
			tmp = BME680_OS_NONE<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_1X:
			tmp = BME680_OS_1X<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_2X:
			tmp = BME680_OS_2X<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_4X:
			tmp = BME680_OS_4X<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_8X:
			tmp = BME680_OS_8X<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	case BME680_OS_16X:
			tmp = BME680_OS_16X<<2;
			bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	break;
	}
}

void bme680_iir_filter(iir_filter_t filter){
	uint8_t tmp;
	switch(filter){
	case BME680_FILTER_OFF:
			tmp = BME680_FILTER_OFF<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_1:
			tmp = BME680_FILTER_SIZE_1<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_3:
			tmp = BME680_FILTER_SIZE_3<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_7:
			tmp = BME680_FILTER_SIZE_7<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_15:
			tmp = BME680_FILTER_SIZE_15<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_31:
			tmp = BME680_FILTER_SIZE_31<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_63:
			tmp = BME680_FILTER_SIZE_63<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	case BME680_FILTER_SIZE_127:
			tmp = BME680_FILTER_SIZE_127<<2;
			bme680_write(BME680_REG_CONFIG,&tmp);
	break;
	}
}


void bme680_soft_reset(){
	uint8_t tmp;
	tmp = BME680_SOFT_RESET_CMD;
	bme680_write(BME680_RESET,&tmp);
	delay_ms(5);
}

static int8_t null_ptr_check(const struct bme680_dev *dev)
{
	int8_t rslt;

	if ((dev == NULL) || (dev->read == NULL) || (dev->write == NULL) || (dev->delay_ms == NULL)) {
		/* Device structure pointer is not valid */
		rslt = BME680_E_NULL_PTR;
	} else {
		/* Device structure is fine */
		rslt = BME680_OK;
	}

	return rslt;
}

int bme680_init(){
	uint8_t tmp,member;
	/* Reset Sensor*/
	bme680_soft_reset();
	/* Check Sensor Chip ID*/
	HAL_I2C_Mem_Read(&BME680_I2C,BME680_I2C_ADDR,BME680_ID, I2C_MEMADD_SIZE_8BIT, &member, 1, I2C_TIMEOUT_MS);
	while(member!=BME68X_CHIP_ID){
		HAL_GPIO_TogglePin(GPIOC, BUZZER_Pin);
		delay_ms(100);
	}
	HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
	/*  Enable FORCED MODE */
	tmp = 0x01;
	bme680_write(BME680_REG_CTRL_MEAS,&tmp);
	/*  Configure the oversampling T P H settings */
	// Configure the Humidity Oversampling
	bme680_oversampling_humidity(BME680_OS_1X);
	// Configure the Temperature Oversampling
	bme680_oversampling_temperature(BME680_OS_2X);
	// Configure the Pressure Oversampling
	bme680_oversampling_pressure(BME680_OS_16X);
	return 0;
}