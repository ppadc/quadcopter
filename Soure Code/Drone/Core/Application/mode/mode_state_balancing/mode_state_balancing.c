/*
 * mode_state_balancing.c
 *
 *  Created on: Mar 31, 2023
 *      Author: nguye
 */
#include <math.h>

#include "mode_state_balancing.h"

static float roll_set_point, pitch_set_point, yaw_set_point;
float tilt_roll, tilt_pitch, tilt_yaw;

static void tilt_controller_callback_euler(){
	tilt_roll = imu_get_roll_euler();
	tilt_pitch = imu_get_pitch_euler();
	tilt_yaw = imu_get_yaw_euler();

	tilt_roll -= params.tilt_roll_offset;
	tilt_pitch -= params.tilt_pitch_offset;
	tilt_yaw -= params.tilt_yaw_offset;

	float roll_speed = pid_compute(&params.PID[0], roll_set_point, tilt_roll, 0.001f*TILT_CONTROLLER_PERIOD_MS);
	float pitch_speed = pid_compute(&params.PID[1], pitch_set_point, tilt_pitch, 0.001f*TILT_CONTROLLER_PERIOD_MS);
#if ENABLE_YAW_CONTROL_TITL == 1
	float yaw_speed = pid_compute(&params.PID[2], yaw_set_point, tilt_yaw, 0.001f*TILT_CONTROLLER_PERIOD_MS);
#endif

#if ENABLE_YAW_CONTROL_TITL == 1
	if(tilt_roll==0 && tilt_pitch == 0 && tilt_yaw == 0){
		roll_speed = 0;
		pitch_speed = 0;
		yaw_speed = 0;
	}
#elif ENABLE_YAW_CONTROL_TITL == 0
	if(tilt_roll==0 && tilt_pitch == 0){
		roll_speed = 0;
		pitch_speed = 0;
	}
#endif
		if(tilt_roll > MAX_TITL_ACCEPT  ||  tilt_roll < MIN_TITL_ACCEPT){
			roll_speed = 0;
			pid_reset(&params.PID[0]);
		}
		if(tilt_pitch > MAX_TITL_ACCEPT ||  tilt_pitch < MIN_TITL_ACCEPT){
			pitch_speed = 0;
			pid_reset(&params.PID[1]);
		}
#if ENABLE_YAW_CONTROL_TITL == 1
		if(tilt_yaw > MAX_TITL_ACCEPT   ||  tilt_yaw < MIN_TITL_ACCEPT){
			yaw_speed = 0;
			pid_reset(&params.PID[2]);
		}
#endif
		float MOTOR_0_SPEED = TRHUST_MOTOR + roll_speed + pitch_speed + yaw_speed;
		float MOTOR_1_SPEED = TRHUST_MOTOR - roll_speed + pitch_speed - yaw_speed;
		float MOTOR_2_SPEED = TRHUST_MOTOR + roll_speed - pitch_speed - yaw_speed;
		float MOTOR_3_SPEED = TRHUST_MOTOR - roll_speed - pitch_speed + yaw_speed;
		motors_setspeed(MOTOR_0, MOTOR_0_SPEED);
		motors_setspeed(MOTOR_1, MOTOR_1_SPEED);
		motors_setspeed(MOTOR_2, MOTOR_2_SPEED);
		motors_setspeed(MOTOR_3, MOTOR_3_SPEED);
}
