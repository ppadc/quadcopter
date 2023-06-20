/*
 * imu.c
 *
 *  Created on: Mar 30, 2023
 *      Author: nguye
 */

#ifndef CORE_APPLICATION_IMU_IMU_C_
#define CORE_APPLICATION_IMU_IMU_C_

#include "imu.h"
#include "params.h"
#include "user_define.h"
#include <math.h>

static float roll_calc;
static float pitch_calc;

static float roll_bno055;
static float pitch_bno055;
static float yaw_bno055;

static float rpy_r,rpy_p,rpy_y;
static float accel[3];
static float gyro[3];

static float mag_x, mag_y, mag_z;
static float magnetometer[3];

static float imu_qua_w, imu_qua_x, imu_qua_y, imu_qua_z;
static float quaternions[4];

TID(gtid_tilt_callback);
TID(gtid_rpy_callback);

static void accel_gyro_callback(void){
	if(bno055_get_accel_gyro(&accel[0],&accel[1],&accel[2],&gyro[0],&gyro[1],&gyro[2])<0) return;
	float accel_roll = atan2(accel[1],sqrt(accel[0]*accel[0]+accel[2]*accel[2]))*180.f/M_PI;
	float accel_pitch = atan2(-accel[0],sqrt(accel[1]*accel[1]+accel[2]*accel[2]))*180.f/M_PI;
	float roll_rate = gyro[0]*0.001f*TILT_CALC_PERIOD_MS;
	float pitch_rate = gyro[1]*0.001f*TILT_CALC_PERIOD_MS;
	roll_calc  = params.g_believe*(roll_calc+roll_rate)+(1-params.g_believe)*accel_roll;
	pitch_calc = params.g_believe*(pitch_calc+pitch_rate)+(1-params.g_believe)*accel_pitch;
	if(isnan(roll_calc)) roll_calc = 0;
	if(isnan(pitch_calc)) pitch_calc = 0;
}

int imu_init(void){
	bno055_initization();
	return 0;
}

int imu_test_connection(){
	return bno055_test();
}

int imu_deint(void){
	return 0;
}

static void	magnetometer_data_callback(void){
	if(bno055_get_mag(&magnetometer[0],&magnetometer[1],&magnetometer[2])<0) return;
	mag_x = magnetometer[0];
	mag_y = magnetometer[1];
	mag_z = magnetometer[2];
}

static void rpy_euler_data_callback(void){
	if(bno055_get_elu_data(&roll_bno055,&pitch_bno055,&yaw_bno055)<0) return;
	rpy_r = roll_bno055;
	rpy_p = pitch_bno055;
	rpy_y = yaw_bno055;
}

static void imu_get_quaternions_data(void){
	if(bno055_get_qua_data(&quaternions[0], &quaternions[1], &quaternions[2], &quaternions[3])<0) return;
	imu_qua_w = quaternions[0];
	imu_qua_x = quaternions[1];
	imu_qua_y = quaternions[2];
	imu_qua_z = quaternions[3];
}

float imu_get_accel(float acc[3]){
	acc[0] = accel[0];
	acc[1] = accel[1];
	acc[2] = accel[2];
	return 0;
}

float imu_get_gyro(float gyr[3]){
	gyr[0] = gyro[0];
	gyr[1] = gyro[1];
	gyr[2] = gyro[2];
	return 0;
}

float imu_get_roll_calc(void){
	return roll_calc;
}

float imu_get_pitch_calc(void){
	return pitch_calc;
}

float imu_get_roll_euler(void){
	return rpy_r;
}

float imu_get_pitch_euler(void){
	return rpy_p;
}

float imu_get_yaw_euler(void){
	return rpy_y;
}

float imu_get_mag(float mag[3]){
	mag[0] = mag_x;
	mag[1] = mag_y;
	mag[2] = mag_z;
	return 0;
}

float imu_get_quaternions(float qua[4]){
	qua[0] = imu_qua_w;
	qua[1] = imu_qua_x;
	qua[2] = imu_qua_y;
	qua[3] = imu_qua_z;
	return 0;
}
#endif /* CORE_APPLICATION_IMU_IMU_C_ */
