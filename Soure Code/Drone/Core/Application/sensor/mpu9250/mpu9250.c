/*
 * mpu9250.c
 *
 *  Created on: Mar 15, 2023
 *      Author: nguye
 */


#include "mpu9250.h"
#include "mpu9250_register_map.h"
#include <string.h>
#include <i2c.h>

#include "user_define.h"

#define GYRO_FS_SEL_250DPS	(0b00 << 3)
#define GYRO_FS_SEL_500DPS	(0b01 << 3)
#define GYRO_FS_SEL_1000DPS	(0b10 << 3)
#define GYRO_FS_SEL_2000DPS	(0b11 << 3)

#define ACCEL_FS_SEL_2G		(0b00 << 3)
#define ACCEL_FS_SEL_4G		(0b01 << 3)
#define ACCEL_FS_SEL_8G		(0b10 << 3)
#define ACCEL_FS_SEL_16G	(0b11 << 3)


static float g_lsb_per_dpfs;
static float g_lsb_per_g;
//static float g_lsb_per_mili_gauss;
static float temp;

static int mpu9250_read(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK){
		*value = 0;
		return -1;
	}
	return 0;
}

static int mpu9250_write(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK)
		return -1;
	return 0;
}

static int mpu9250_read_bytes(uint8_t addr, uint8_t* value, uint8_t len){
	if(HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK){
		memset(value, 0, len);
		return -1;
	}
	return 0;
}

//static int mpu9250_write_bytes(uint8_t addr, uint8_t* value, uint8_t len){
//	if(HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}

//static int ak8963_read(uint8_t addr, uint8_t *value){
//	if(HAL_I2C_Mem_Read(&MPU9250_I2C, AK8963_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK){
//		*value = 0;
//		return -1;
//	}
//	return 0;
//}
//
//static int ak8963_write(uint8_t addr, uint8_t *value){
//	if(HAL_I2C_Mem_Write(&MPU9250_I2C, AK8963_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}
//
//static int ak8963_read_bytes(uint8_t addr, uint8_t *value, uint8_t len){
//	if(HAL_I2C_Mem_Read(&MPU9250_I2C, AK8963_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK){
//		memset(value, 0, len);
//		return -1;
//	}
//	return 0;
//}

//static int ak8963_write_bytes(uint8_t addr, uint8_t *value, uint8_t len){
//	if(HAL_I2C_Mem_Write(&MPU9250_I2C, AK8963_I2C_ADDR, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}


//static int hmc5883l_read(uint8_t addr, uint8_t *value){
//	if(HAL_I2C_Mem_Read(&HMC5883L_I2C, HMC5883L_ADDRESS, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK){
//		*value = 0;
//		return -1;
//	}
//	return 0;
//}
//
//static int hmc5883l_write(uint8_t addr, uint8_t *value){
//	if(HAL_I2C_Mem_Write(&HMC5883L_I2C, HMC5883L_ADDRESS, addr, I2C_MEMADD_SIZE_8BIT, value, 1, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}
//
//static int hmc5883l_read_bytes(uint8_t addr, uint8_t* value, uint8_t len){
//	if(HAL_I2C_Mem_Read(&HMC5883L_I2C, HMC5883L_ADDRESS, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK){
//		memset(value, 0, len);
//		return -1;
//	}
//	return 0;
//}

//static int hmc5883l_write_bytes(uint8_t addr, uint8_t* value, uint8_t len){
//	if(HAL_I2C_Mem_Write(&HMC5883L_I2C, HMC5883L_ADDRESS, addr, I2C_MEMADD_SIZE_8BIT, value, len, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}


int mpu9250_init(){
	uint8_t tmp;
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//
//	uint8_t Data;
//	//Data = 0x00;
//	Data = 0x00;                                             //0x6B
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, MPU9250_PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//	for(int i=0;i<10;i++)for(int j=0;j<1000;j++)__NOP();
//
//	Data = 0x07;
//	//Data = 0x02;
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, 0x19, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//	//HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, MPU9250_INT_PIN_CFG, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//
//	Data = 0x01;
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, 0x38, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//	//HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, MPU9250_INT_PIN_CFG, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//
//	Data = 0x00;
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, 0x6A, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
///////////////////
	// Reset mpu9250
	tmp = 0x80; // H_RESET
	if(mpu9250_write(MPU9250_PWR_MGMT_1, &tmp) < 0) return -1;
	for(int i=0;i<10;i++)for(int j=0;j<1000;j++)__NOP();

	// Enable I2C bypass mode
	tmp = 0x02; // BYPASS_EN
	if(mpu9250_write(MPU9250_INT_PIN_CFG, &tmp) < 0) return -1;

//	// Reset AK8963
//	tmp = 0x01; // SRST
//	if(ak8963_write(AK8963_CNTL2, &tmp) < 0);

	if(mpu9250_test() < 0) return -1;

	// Set mpu9250 clock source
	tmp = 0x01; // CLKSEL
	if(mpu9250_write(MPU9250_PWR_MGMT_1, &tmp) < 0) return -1;

/////////////////////////////////////////
//	uint8_t Data;
	//exit sleep mode
//	Data = 0x00;
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, MPU9250_PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
//	for(int i=0;i<10;i++)for(int j=0;j<1000;j++)__NOP();
//	//sample rate
//	Data = 109;
//	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, MPU9250_SMPLRT_DIV, I2C_MEMADD_SIZE_8BIT, &Data, 1, I2C_TIMEOUT_MS);
////////////////////////////////////////////


#if GFS_SEL==0
		tmp = GYRO_FS_SEL_250DPS;
		if(mpu9250_write(MPU9250_GYRO_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_dpfs = 131.f;
#elif GFS_SEL==1
		tmp = GYRO_FS_SEL_500DPS;
		if(mpu9250_write(MPU9250_GYRO_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_dpfs = 65.5f;
#elif GFS_SEL==2
		tmp = GYRO_FS_SEL_1000DPS;
		if(mpu9250_write(MPU9250_GYRO_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_dpfs = 32.8f;
#elif GFS_SEL==3
		tmp = GYRO_FS_SEL_2000DPS;
		if(mpu9250_write(MPU9250_GYRO_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_dpfs = 16.4f;
#endif

#if ACCEL_FS_SEL==0
		tmp = ACCEL_FS_SEL_2G;
		if(mpu9250_write(MPU9250_ACCEL_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_g = 16384.f;
#elif ACCEL_FS_SEL==1
		tmp = ACCEL_FS_SEL_4G;
		if(mpu9250_write(MPU9250_ACCEL_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_g = 8192.f;
#elif ACCEL_FS_SEL==2
		tmp = ACCEL_FS_SEL_8G;
		if(mpu9250_write(MPU9250_ACCEL_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_g = 4096.f;
#elif ACCEL_FS_SEL==3
		tmp = ACCEL_FS_SEL_16G;
		if(mpu9250_write(MPU9250_ACCEL_CONFIG, &tmp) < 0) return -1;
		g_lsb_per_g = 2048.f;
#endif

//	tmp = 0x00; // Power-down mode
//	if(ak8963_write(AK8963_CNTL1, &tmp) < 0);
//	for(int i=0;i<10;i++)for(int j=0;j<1000;j++)__NOP();
//
//	tmp = 0x16; // Continuous measurement mode 2 + 16 bit resolution
//	if(ak8963_write(AK8963_CNTL1, &tmp) < 0);
//	g_lsb_per_mili_gauss = 32760.0f/4912.f;

	tmp = 0x01;
	mpu9250_write(MPU9250_INT_ENABLE, &tmp);
	/////////////////
//	//config HMC5883Ｌ
//	tmp = 0x00;
//	mpu9250_write(MPU9250_USER_CTRL, &tmp);
//	tmp = 0x02;
//	mpu9250_write(MPU9250_INT_PIN_CFG, &tmp);
//	tmp = 0x18;
//	hmc5883l_write(HMC5883L_RA_CONFIG_A, &tmp);
//	tmp = 0x60;
//	hmc5883l_write(HMC5883L_RA_CONFIG_B, &tmp);
//	tmp = 0x00;
//	hmc5883l_write(HMC5883L_RA_MODE_REGISTER, &tmp);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	return 0;
}

int mpu9250_test(){
	uint8_t tmp;

	mpu9250_read(MPU9250_WHO_AM_I, &tmp);
	if(tmp!=0x68) return -1;

//	ak8963_read(AK8963_WIA, &tmp);
//	if(tmp!=AK8963_WAI_RESULT);

	return 0;
}

int mpu9250_get_accel_gyro(float *ax, float *ay, float *az, float *gx, float *gy, float *gz){
	uint8_t buffer[14] = {};
	if(mpu9250_read_bytes(MPU9250_ACCEL_XOUT_H, buffer, 14) < 0){
		return -1;
	}
    *ax = (int16_t)((int16_t)buffer[0]  << 8) | buffer[1];	*ax /= g_lsb_per_g; ///acc_x
    *ay = (int16_t)((int16_t)buffer[2]  << 8) | buffer[3];  *ay /= g_lsb_per_g;	///acc_y
    *az = (int16_t)((int16_t)buffer[4]  << 8) | buffer[5];  *az /= g_lsb_per_g;	///acc_z
    temp = (int16_t)((int16_t)buffer[6]  << 8) | buffer[7]; temp /= 340.0f; temp += 36.53; //temp
    *gx = (int16_t)((int16_t)buffer[8]  << 8) | buffer[9];	*gx /= g_lsb_per_dpfs; ///gyro_x
    *gy = (int16_t)((int16_t)buffer[10] << 8) | buffer[11]; *gy /= g_lsb_per_dpfs; ///gyro_y
    *gz = (int16_t)((int16_t)buffer[12] << 8) | buffer[13]; *gz /= g_lsb_per_dpfs; ///gyro_z
	return 0;
}

float mpu9250_gettemp(void){
	return temp;
}

//int mpu9250_get_mag(float *mx, float *my, float *mz){
//	uint8_t tmp;
//	uint8_t raw[7];
//	int16_t mag_raw[3];
//	if(ak8963_read(AK8963_ST1, &tmp) < 0){
//		return -1;
//	}
//	else if(tmp & 0x01){
//		ak8963_read_bytes(AK8963_HXL, raw, 7);
//        uint8_t c = raw[6];                                         		// End data read by reading ST2 register
//        if (!(c & 0x08)) {                                               	// Check if magnetic sensor overflow set, if not then report data
//        	mag_raw[0] = ((int16_t)raw[1] << 8) | raw[0];  					// Turn the MSB and LSB into a signed 16-bit value
//        	mag_raw[1] = ((int16_t)raw[3] << 8) | raw[2];  					// Data stored as little Endian
//        	mag_raw[2] = ((int16_t)raw[5] << 8) | raw[4];
//        }
//        else return -1;
//	}
//	else{
//		return -1;
//	}
//	*mx = mag_raw[0]/g_lsb_per_mili_gauss;
//	*my = mag_raw[1]/g_lsb_per_mili_gauss;
//	*mz = mag_raw[2]/g_lsb_per_mili_gauss;
//	return 0;
//}



