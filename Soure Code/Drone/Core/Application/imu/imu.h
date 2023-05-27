/*
 * imu.h
 *
 *  Created on: Mar 30, 2023
 *      Author: nguye
 */

#ifndef CORE_APPLICATION_IMU_IMU_H_
#define CORE_APPLICATION_IMU_IMU_H_

#include "bno055.h"
#include "mpu9250.h"
#include "timer.h"
#include <stdbool.h>

typedef void (*connection_failed_cb_t)(void);

int  imu_init(void);
int  imu_deinit(void);
int imu_test_connection();

float imu_get_accel(float acc[3]);
float imu_get_gyro(float gyr[3]);
float imu_get_roll_calc(void);
float imu_get_pitch_calc(void);
float imu_get_roll_euler(void);
float imu_get_pitch_euler(void);
float imu_get_yaw_euler(void);
float imu_get_mag(float mag[3]);
float imu_get_quaternions(float qua[4]);

#endif /* CORE_APPLICATION_IMU_IMU_H_ */
