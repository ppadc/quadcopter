/*
 * params.h
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_PARAMS_PARAMS_H_
#define APPLICATION_PARAMS_PARAMS_H_

#include <stdint.h>
#include "params.h"
#include "pid.h"

typedef struct{
	pid_params_t PID[4];
	float tilt_roll_offset;
	float tilt_pitch_offset;
	float tilt_yaw_offset;

	float g_believe;

	float gx_bias;
	float gy_bias;
	float gz_bias;

	float ax_bias;
	float ay_bias;
	float az_bias;

	float mx_bias;
	float my_bias;
	float mz_bias;

	float mx_scale;
	float my_scale;
	float mz_scale;

	int16_t motor0_deadband;
	int16_t motor1_deadband;
	int16_t motor2_deadband;
	int16_t motor3_deadband;

	//define MPC Constants (Astec Hummingbird)
    float MPC_Cons_Ix;     //kg*m^2
    float MPC_Cons_Iy;     //kg*m^2
    float MPC_Cons_Iz;     //kg*m^2
    float MPC_Cons_m;      //kg
	float MPC_Cons_g;      //m/s^2
	double MPC_Cons_Jtp;   //N*m*s^2=kg*m^2
	float MPC_Cons_Ts;	   //s

	//Matrix weights for the cost function (They must be diagonal)
	unsigned char MPC_Cons_Q[3][3];         //weights for outputs (all samples, except the last one)
	unsigned char MPC_Cons_S[3][3]; 		//weights for the final horizon period outputs
	unsigned char MPC_Cons_R[3][3];			//weights for inputs

	double MPC_Cons_ct;
	double MPC_Cons_cq;

	float MPC_Cons_l;

	unsigned char MPC_Cons_controlled_states;
	unsigned char MPC_Cons_hz;
	unsigned char MPC_Cons_innerDyn_length;

	char MPC_Cons_px[1][2];
	char MPC_Cons_py[1][2];
	char MPC_Cons_pz[1][2];

	char  MPC_Cons_r;
	float MPC_Cons_f;
	char  MPC_Cons_height_i;
	char  MPC_Cons_height_f;
	int   MPC_Cons_Sub_loop;
	int   MPC_Cons_drag_switch;
	//Drag force coefficients [-]:
	float MPC_Cons_C_D_u;
	float MPC_Cons_C_D_v;
	float MPC_Cons_C_D_w;
	//Drag force cross-section area [m^2]
	float MPC_Cons_A_u;
	float MPC_Cons_A_v;
	float MPC_Cons_A_w;
	//Air density
	float MPC_Cons_rho;
	char MPC_Cons_trajectory;
}params_t;

extern params_t params;

void params_save();
bool params_load();

#endif /* APPLICATION_PARAMS_PARAMS_H_ */
