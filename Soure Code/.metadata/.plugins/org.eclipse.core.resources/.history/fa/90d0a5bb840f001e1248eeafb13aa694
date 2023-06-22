/*
 * user_define.h
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */

#ifndef INC_USER_DEFINE_H_
#define INC_USER_DEFINE_H_


#include "main.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "delay_us.h"
#include "imu.h"

/* Timer callback define */
#define MAX_CALLBACK_FUNC								20
#define TIM_DELAY_US									htim5
#define TIM_DELAY_MS									htim5
/* PID define */
#define PID_CONTROL_TYPE								1
// PID_CONTROL_TYPE_VDK		--> 0
// PID_CONTROL_TYPE_ROI_RAC	--> 1
/* Parameters define */
#define PARAMS_PAGE_ADDRESS  							0x080E0000

//Flash Module Origanization (STM32F40X and STM32F41X)
#define ADDR_FLASH_SECTOR_0								0x08000000	//16Kbytes
#define ADDR_FLASH_SECTOR_1								0x08004000	//16Kbytes
#define ADDR_FLASH_SECTOR_2								0x08008000	//16Kbytes
#define ADDR_FLASH_SECTOR_3								0x0800C000	//16Kbytes
#define ADDR_FLASH_SECTOR_4								0x08010000	//64Kbytes
#define ADDR_FLASH_SECTOR_5								0x08020000	//128Kbytes
#define ADDR_FLASH_SECTOR_6								0x08040000	//128Kbytes
#define ADDR_FLASH_SECTOR_7								0x08060000	//128Kbytes
#define ADDR_FLASH_SECTOR_8								0x08080000	//128Kbytes
#define ADDR_FLASH_SECTOR_9								0x080A0000	//128Kbytes
#define ADDR_FLASH_SECTOR_10							0x080C0000	//128Kbytes
#define ADDR_FLASH_SECTOR_11							0x080E0000	//128Kbytes

#define HAVE_SAVED_DATA  								0x01

/* MPC definition */
#define DRAG_FORCE_SWITCH								0
//OFF 				0
//ON 				1

/* IMU definition */
//* BNO055_DEFINE_FUNC *//
#define BNO055__I2C 		hi2c1
#define MPU9250_I2C 		hi2c1
#define BME680_I2C 			hi2c1
#define SSD1306_I2C			hi2c1
#define I2C_RETURN				1
//RETURN_SYS_ON					1
//RETURN_SYS_OFF 				0

#define BME680_STATUS 									0
//HIGH 				1
//LOW 				0

#define SSD1306_STATUS 									0
//0X78 				0
//0X7A 				1

#define BNO055_STATUS 									0
// ADR_Pin is LOW or not connect	--> 0
// ADR_Pin is HIGH 					--> 1
	#if BNO055_STATUS == 0
	#define BNO055_I2C_ADDR 	(0x28 << 1)
	#elif BNO055_STATUS == 1
	#define BNO055_I2C_ADDR 	(0x29 << 1)
	#endif
#define BNO055_POWER_MODE		  						0
//Normal Mode 						0   // All Sensor required for the selected operating mode
//Low Power Mode 					1   // If no activity (i.e. no motion) is detected (default 5 seconds) BNO055 enters the low power mode. Only accelerometer is active. When once motion is detected, normal mode is entered
//Suspend Mode						2	// the system is paused and all the sensors and the microcontroller are put into sleep mode.

#define BNO055_MODE_IMU 								1
// MODE_DEFAULT_CONFIGUARATIONS		--> 0
// MODE_CONFIGURATIONS 				--> 1
#define BNO055_ACC_G_RANGE_VALUES 						1
// G RANGE = 2G						--> 0
// G RANGE = 4G 					--> 1
// G RANGE = 8G 					--> 2
// G RANGE = 16G 					--> 3
#define BNO055_ACC_BANDWIDTH_VALUES 					3
// BANDWIDTH = 7.81Hz				--> 0
// BANDWIDTH = 15.63Hz 				--> 1
// BANDWIDTH = 31.25Hz 				--> 2
// BANDWIDTH = 62.5Hz 				--> 3
// BANDWIDTH = 125Hz 				--> 4
// BANDWIDTH = 250Hz 				--> 5
// BANDWIDTH = 500Hz 				--> 6
// BANDWIDTH = 1000Hz 				--> 7
#define BNO055_ACC_MODE_VALUES							0
// MODE_NORMAL 						--> 0
// MODE_SUSPEND 					--> 1
// MODE_LOW_POWER_1 				--> 2
// MODE_STANDBY  					--> 3
// MODE_LOW_POWER_2  				--> 4
// MODE_DEEP_SUSPEND 				--> 5

#define BNO055_GYR_RANGE_VALUES 						0
// RANGE = 2000DPS 					--> 0
// RANGE = 1000DPS					--> 1
// RANGE = 500DPS 					--> 2
// RANGE = 250DPS 					--> 3
// RANGE = 125DPS 					--> 4
#define BNO055_GYR_BANDWIDTH_VALUES 					7
// BANDWIDTH = 523Hz				--> 0
// BANDWIDTH = 230Hz 				--> 1
// BANDWIDTH = 116Hz 				--> 2
// BANDWIDTH = 47Hz 				--> 3
// BANDWIDTH = 23Hz 				--> 4
// BANDWIDTH = 12Hz 				--> 5
// BANDWIDTH = 64Hz 				--> 6
// BANDWIDTH = 32Hz 				--> 7
#define BNO055_GYR_MODE_VALUES 							0
// MODE_NORMAL 						--> 0
// MODE_FAST_POWER_UP				--> 1
// MODE_DEEP_SUSPEND 				--> 2
// MODE_SUSPEND 					--> 3
// MODE_ADVANCED_POWERSAVE 			--> 4

#define BNO055_MAG_DATA_OUTPUT_RATE_VALUES 				3
// RATE = 2Hz 						--> 0
// RATE = 6Hz						--> 1
// RATE = 8Hz 						--> 2
// RATE = 10Hz 						--> 3
// RATE = 15Hz 						--> 4
// RATE = 20Hz 						--> 5
// RATE = 25Hz						--> 6
// RATE = 30Hz 						--> 7
#define BNO055_MAG_OPERATION_MODE_VALUES 				3
// MODE_LOW_POWER 					--> 0
// MODE_REGULAR						--> 1
// MODE_ENHANCED_REGULAR 			--> 2
// MODE_HIGH_ACCURACY 				--> 3

#define BNO055_MAG_PWR_MODE_VALUES						3
// MODE_NORMAL 						--> 0
// MODE_SLEEP						--> 1
// MODE_SUSPEND 					--> 2
// MODE_FORCE_MODE 					--> 3

#define BNO055_ACCEL_LINEARACC_GRAVITYVECTOR_UNITS 		0
// M/S2								--> 0
// MG								--> 1
#define BNO055_ANGULAR_RATE_UNITS				   		0
// DPS								--> 0
// RPS								--> 1
#define BNO055_EULER_ANGLES_UNITS						0
// Degress 							--> 0
// Radians 							--> 1
#define BNO055_TEMPERATURE_UNITS						0
// C	 							--> 0
// F								--> 1

//MPU9250_DEFINE_FUNC
#define MPU9250_I2C_ADDR 		(0x68 << 1)
#define AK8963_I2C_ADDR			(0x0C << 1)

/*BME680_DEFINE_FUNC*/
#if BME680_STATUS == 0
#define BME680_I2C_ADDR			(0x76 << 1)
#elif BME680_STATUS == 1
#define BME680_I2C_ADDR			(0x77 << 1)
#endif

/*Configure the oversampling settings */
#define BME680_OVERSAMPLING_HUMIDITY 			1
// OVERSAMPLING_SKIPPED 			--> 0
// OVERSAMPLING_X1 					--> 1
// OVERSAMPLING_X2					--> 2
// OVERSAMPLING_X4 					--> 3
// OVERSAMPLING_X8 					--> 4
// OVERSAMPLING_X16 				--> 5

/*SSD1306_DEFINE_FUNC*/
#if SSD1306_STATUS == 0
#define SSD1306_STATUS_I2C_ADDR			(0x78 << 1)
#elif SSD1306_STATUS == 1
#define SSD1306_STATUS_ADDR			(0x7A << 1)
#endif

#define I2C_TIMEOUT_MS			100

/*IMU Define*/
#define TILT_CALC_PERIOD_MS 						5

/*Define Mode*/
#define TILT_CONTROLLER_PERIOD_MS		1
#define ENABLE_YAW_CONTROL_TITL			1
//DISABLE								0
//ENABLE								1

#define MAX_TITL_ACCEPT				 60
#define MIN_TITL_ACCEPT				-60

/*MOTOR Define*/
#define MOTOR0_TIMER 		htim1
#define MOTOR0_CHANNEL 		TIM_CHANNEL_1

#define MOTOR1_TIMER 		htim1
#define MOTOR1_CHANNEL 		TIM_CHANNEL_2

#define MOTOR2_TIMER 		htim1
#define MOTOR2_CHANNEL 		TIM_CHANNEL_3

#define MOTOR3_TIMER 		htim1
#define MOTOR3_CHANNEL 		TIM_CHANNEL_4

#define THRUST_MOTOR_MAX 	1800
#define TRHUST_MOTOR		800
/* UART DEFINE */
#define MAX_UART_INSTANT	3
#define TX_DMA_BUF_SIZE 	512
#define RX_DMA_BUF_SIZE		512
#define TX_CIR_BUF_SIZE 	512
#define RX_CIR_BUF_SIZE 	512

// Mavlink
#define MAV_BUFF_SIZE 		128
#define MAVLINK_CB_PERIOD	15	// Mavlink read message callback

// Serial to DWM1001
#define STD_USART			huart1
#define STD_PERIOD			100

// Serial over ESP8266
#define SOE_USART			huart2
#define SOE_PERIOD			100

// Serial over UART define
#define SOU_USART			huart3
#define SOU_PERIOD			100

#endif /* INC_USER_DEFINE_H_ */
