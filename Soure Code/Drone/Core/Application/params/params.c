/*
 * params.c
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */


#include "params.h"
#include "user_define.h"
#include <stm32f4xx.h>
#include <math.h>

params_t params={
#if PID_CONTROL_TYPE == 0
		.PID[0]={
				.KP=0,
				.KI=0,
				.KD=0,
				.minIpart = -2000,
				.maxIpart = 2000,
				.minDpart = -2000,
				.maxDpart = 2000,
				.minOut = -2000,
				.maxOut = 2000,

				.preIPart = 0,
				.preError = 0,
				.isFirstCompute = true
		},

		.PID[1]={
				.KP=0,
				.KI=0,
				.KD=0,
				.minIpart = -2000,
				.maxIpart = 2000,
				.minDpart = -2000,
				.maxDpart = 2000,
				.minOut = -2000,
				.maxOut = 2000,

				.preIPart = 0,
				.preError = 0,
				.isFirstCompute = true
		},

		.PID[2]={
				.KP=0,
				.KI=0,
				.KD=0,
				.minIpart = -2000,
				.maxIpart = 2000,
				.minDpart = -2000,
				.maxDpart = 2000,
				.minOut = -2000,
				.maxOut = 2000,

				.preIPart = 0,
				.preError = 0,
				.isFirstCompute = true
		},

		.PID[3]={
				.KP=0,
				.KI=0,
				.KD=0,
				.minIpart = -2000,
				.maxIpart = 2000,
				.minDpart = -2000,
				.maxDpart = 2000,
				.minOut = -2000,
				.maxOut = 2000,

				.preIPart = 0,
				.preError = 0,
				.isFirstCompute = true
		},
#elif PID_CONTROL_TYPE == 1
		.PID[0]={
				.KP=0,
				.KI=0,
				.KD=0,
				.min_alpha_part = -2000,
				.max_alpha_part = 2000,
				.min_beta_part = -2000,
				.max_beta_part = 2000,
				.min_gamma_part = -2000,
				.max_gamma_part = 2000,

				.preError  = 0,
				.pre2Error = 0,
				.isFirstCompute = true,
		},
		.PID[1]={
				.KP=0,
				.KI=0,
				.KD=0,
				.min_alpha_part = -2000,
				.max_alpha_part = 2000,
				.min_beta_part = -2000,
				.max_beta_part = 2000,
				.min_gamma_part = -2000,
				.max_gamma_part = 2000,

				.preError  = 0,
				.pre2Error = 0,
				.isFirstCompute = true,
		},
		.PID[2]={
				.KP=0,
				.KI=0,
				.KD=0,
				.min_alpha_part = -2000,
				.max_alpha_part = 2000,
				.min_beta_part = -2000,
				.max_beta_part = 2000,
				.min_gamma_part = -2000,
				.max_gamma_part = 2000,

				.preError  = 0,
				.pre2Error = 0,
				.isFirstCompute = true,
		},
		.PID[3]={
				.KP=0,
				.KI=0,
				.KD=0,
				.min_alpha_part = -2000,
				.max_alpha_part = 2000,
				.min_beta_part = -2000,
				.max_beta_part = 2000,
				.min_gamma_part = -2000,
				.max_gamma_part = 2000,

				.preError  = 0,
				.pre2Error = 0,
				.isFirstCompute = true,
		},
#endif
		.tilt_pitch_offset = 0,
		.tilt_roll_offset = 0,
		.tilt_yaw_offset = 0,

		.g_believe = 0.99,

		.ax_bias = 0,
		.ay_bias = 0,
		.az_bias = 0,

		.gx_bias = 0,
		.gy_bias = 0,
		.gz_bias = 0,

		.mx_bias = 0,
		.my_bias = 0,
		.mz_bias = 0,

		.mx_scale = 0,
		.my_scale = 0,
		.mz_scale = 0,

		//MPC Constants Values (Astec Hummingbird)
		.MPC_Cons_Ix = 0.0034,
		.MPC_Cons_Iy = 0.0034,
		.MPC_Cons_Iz = 0.006,
		.MPC_Cons_m = 1.698,
		.MPC_Cons_g = 9.81,
		.MPC_Cons_Jtp = 1.302/1000000,
		.MPC_Cons_Ts = 0.1,
		.MPC_Cons_ut = 0,
		.MPC_Cons_vt = 0,
		.MPC_Cons_wt = 0,
		.MPC_Cons_pt = 0,
		.MPC_Cons_qt = 0,
		.MPC_Cons_rt = 0,
		.MPC_Cons_xt = 0,
		.MPC_Cons_yt = -1,
		.MPC_Cons_zt = -1,
		.MPC_Cons_phit = 0,
		.MPC_Cons_thetat = 0,
		.MPC_Cons_psit = 0,

		.MPC_Cons_omega1 = 110*M_PI/3, // rad/s at t=-Ts s (Ts seconds before NOW)
		.MPC_Cons_omega2 = 110*M_PI/3, // rad/s at t=-Ts s (Ts seconds before NOW)
		.MPC_Cons_omega3 = 110*M_PI/3, // rad/s at t=-Ts s (Ts seconds before NOW)
		.MPC_Cons_omega4 = 110*M_PI/3, // rad/s at t=-Ts s (Ts seconds before NOW)

		.MPC_Cons_Q = {
				{10,0,0},
				{0,10,0},
				{0,0,10}
		},
		.MPC_Cons_S = {
				{20,0,0},
				{0,20,0},
				{0,0,20}
		},
		.MPC_Cons_R = {
				{10,0,0},
				{0,10,0},
				{0,0,10}
		},
		.MPC_Cons_ct = 6.9471/1000000,
		.MPC_Cons_cq = 0.2447/1000000,
		.MPC_Cons_l  = 0.171,
		.MPC_Cons_controlled_states = 3,
		.MPC_Cons_hz = 4,
		.MPC_Cons_innerDyn_length = 4,

		.MPC_Cons_px = {
				{-1,-2}
		},
		.MPC_Cons_py = {
				{-1,-2}
		},
		.MPC_Cons_pz = {
				{-1,-2}
		},

		.MPC_Cons_r = 2,
		.MPC_Cons_f = 0.025,
		.MPC_Cons_height_i = 1,
		.MPC_Cons_height_f = 5,
		.MPC_Cons_drag_switch = 0,
		.MPC_Cons_C_D_u = 1.5,
		.MPC_Cons_C_D_v = 1.5,
		.MPC_Cons_C_D_w = 2.0,
		.MPC_Cons_A_u = (2*0.171*0.01)+0.0025,  	//0.171 la MPC_Cons_l
		.MPC_Cons_A_v = (2*0.171*0.01)+0.0025,		//0.171 la MPC_Cons_l
		.MPC_Cons_A_w = (2*2*0.171*0.01)+0.0025,	//0.171 la MPC_Cons_l
		.MPC_Cons_Sub_loop = 5,
		.MPC_Cons_rho = 1.225,
		.MPC_Cons_trajectory = 1,
};

static uint32_t address = PARAMS_PAGE_ADDRESS;

static void write_1byte(uint32_t* ptr){
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *ptr);
	address+=1;
}

static void read_1byte(uint8_t* ptr){
	*ptr = *((__IO uint8_t*)address);
	address+=1;
}

static void write_4bytes(uint32_t* ptr){
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *ptr);
	address+=4;
}

static void read_4bytes(uint32_t* ptr){
	*ptr = *((__IO uint32_t*)address);
	address+=4;
}

static void write_8bytes(uint64_t* ptr){
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *ptr);
	address+=8;
}

static void read_8bytes(uint64_t* ptr){
	*ptr = *((__IO uint64_t*)address);
	address+=8;
}

void params_save(){
	HAL_FLASH_Unlock();
		FLASH_EraseInitTypeDef EraseInitStruct;
		EraseInitStruct.TypeErase   = FLASH_TYPEERASE_SECTORS;
		EraseInitStruct.Sector = FLASH_SECTOR_11;
		EraseInitStruct.NbSectors     = 1;
		EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3;

		uint32_t SectorError = 0;
		HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError);

		address = PARAMS_PAGE_ADDRESS;

		uint32_t saved_32 = HAVE_SAVED_DATA;
		uint64_t saved_64 = HAVE_SAVED_DATA;
		write_1byte(&saved_32);
		write_4bytes(&saved_32);
		write_8bytes(&saved_64);

		//PID_Control_Data
		write_4bytes((uint32_t*)(&params.PID[0].KP));
		write_4bytes((uint32_t*)(&params.PID[0].KI));
		write_4bytes((uint32_t*)(&params.PID[0].KD));

		write_4bytes((uint32_t*)(&params.PID[1].KP));
		write_4bytes((uint32_t*)(&params.PID[1].KI));
		write_4bytes((uint32_t*)(&params.PID[1].KD));

		write_4bytes((uint32_t*)(&params.PID[2].KP));
		write_4bytes((uint32_t*)(&params.PID[2].KI));
		write_4bytes((uint32_t*)(&params.PID[2].KD));

		write_4bytes((uint32_t*)(&params.PID[3].KP));
		write_4bytes((uint32_t*)(&params.PID[3].KI));
		write_4bytes((uint32_t*)(&params.PID[3].KD));

		//IMU_Data
		write_4bytes((uint32_t*)(&params.tilt_roll_offset));
		write_4bytes((uint32_t*)(&params.tilt_pitch_offset));
		write_4bytes((uint32_t*)(&params.tilt_yaw_offset));
		write_4bytes((uint32_t*)(&params.g_believe));

		write_4bytes((uint32_t*)(&params.gx_bias));
		write_4bytes((uint32_t*)(&params.gy_bias));
		write_4bytes((uint32_t*)(&params.gz_bias));

		write_4bytes((uint32_t*)(&params.ax_bias));
		write_4bytes((uint32_t*)(&params.ay_bias));
		write_4bytes((uint32_t*)(&params.az_bias));

		write_4bytes((uint32_t*)(&params.mx_bias));
		write_4bytes((uint32_t*)(&params.my_bias));
		write_4bytes((uint32_t*)(&params.mz_bias));

		write_4bytes((uint32_t*)(&params.mx_scale));
		write_4bytes((uint32_t*)(&params.my_scale));
		write_4bytes((uint32_t*)(&params.mz_scale));

		//MPC Saved Params
		write_4bytes((uint32_t*)(&params.MPC_Cons_Ix));
		write_4bytes((uint32_t*)(&params.MPC_Cons_Iy));
		write_4bytes((uint32_t*)(&params.MPC_Cons_Iz));

		write_4bytes((uint32_t*)(&params.MPC_Cons_m));
		write_4bytes((uint32_t*)(&params.MPC_Cons_g));
		write_8bytes((uint64_t*)(&params.MPC_Cons_Jtp));
		write_4bytes((uint32_t*)(&params.MPC_Cons_Ts));
		write_4bytes((uint32_t*)(&params.MPC_Cons_ut));
		write_4bytes((uint32_t*)(&params.MPC_Cons_vt));
		write_4bytes((uint32_t*)(&params.MPC_Cons_wt));

		write_4bytes((uint32_t*)(&params.MPC_Cons_pt));
		write_4bytes((uint32_t*)(&params.MPC_Cons_qt));
		write_4bytes((uint32_t*)(&params.MPC_Cons_rt));

		write_4bytes((uint32_t*)(&params.MPC_Cons_xt));
		write_4bytes((uint32_t*)(&params.MPC_Cons_yt));
		write_4bytes((uint32_t*)(&params.MPC_Cons_zt));

		write_4bytes((uint32_t*)(&params.MPC_Cons_phit));
		write_4bytes((uint32_t*)(&params.MPC_Cons_thetat));
		write_4bytes((uint32_t*)(&params.MPC_Cons_psit));

		write_4bytes((uint32_t*)(&params.MPC_Cons_omega1));
		write_4bytes((uint32_t*)(&params.MPC_Cons_omega2));
		write_4bytes((uint32_t*)(&params.MPC_Cons_omega3));
		write_4bytes((uint32_t*)(&params.MPC_Cons_omega4));

		unsigned char i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_Q[i][j]));
			}
		}
		i=0;j=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_S[i][j]));
			}
		}
		i=0;j=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_R[i][j]));
			}
		}
		write_8bytes((uint64_t*)(&params.MPC_Cons_ct));
		write_8bytes((uint64_t*)(&params.MPC_Cons_cq));
		write_4bytes((uint32_t*)(&params.MPC_Cons_l));

		write_1byte((uint32_t*)(&params.MPC_Cons_controlled_states));
		write_1byte((uint32_t*)(&params.MPC_Cons_hz));
		write_1byte((uint32_t*)(&params.MPC_Cons_innerDyn_length));

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_px[i][j]));
			}
		}

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_py));
			}
		}

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				write_1byte((uint32_t*)(&params.MPC_Cons_pz));
			}
		}

		write_1byte((uint32_t*)(&params.MPC_Cons_r));
		write_4bytes((uint32_t*)(&params.MPC_Cons_f));
		write_1byte((uint32_t*)(&params.MPC_Cons_height_i));
		write_1byte((uint32_t*)(&params.MPC_Cons_height_f));
		write_4bytes((uint32_t*)(&params.MPC_Cons_drag_switch));
		write_4bytes((uint32_t*)(&params.MPC_Cons_C_D_u));
		write_4bytes((uint32_t*)(&params.MPC_Cons_C_D_v));
		write_4bytes((uint32_t*)(&params.MPC_Cons_C_D_w));
		write_4bytes((uint32_t*)(&params.MPC_Cons_A_u));
		write_4bytes((uint32_t*)(&params.MPC_Cons_A_v));
		write_4bytes((uint32_t*)(&params.MPC_Cons_A_w));
		write_4bytes((uint32_t*)(&params.MPC_Cons_Sub_loop));
		write_4bytes((uint32_t*)(&params.MPC_Cons_rho));
		write_1byte((uint32_t*)(&params.MPC_Cons_trajectory));
		HAL_FLASH_Lock();
}

bool params_load(){
	address = PARAMS_PAGE_ADDRESS;
	if((*(__IO uint32_t*) address) != HAVE_SAVED_DATA) return false;
		address+=4;

		read_4bytes((uint32_t*)(&params.PID[0].KP));
		read_4bytes((uint32_t*)(&params.PID[0].KI));
		read_4bytes((uint32_t*)(&params.PID[0].KD));

		read_4bytes((uint32_t*)(&params.PID[1].KP));
		read_4bytes((uint32_t*)(&params.PID[1].KI));
		read_4bytes((uint32_t*)(&params.PID[1].KD));

		read_4bytes((uint32_t*)(&params.PID[2].KP));
		read_4bytes((uint32_t*)(&params.PID[2].KI));
		read_4bytes((uint32_t*)(&params.PID[2].KD));

		read_4bytes((uint32_t*)(&params.PID[3].KP));
		read_4bytes((uint32_t*)(&params.PID[3].KI));
		read_4bytes((uint32_t*)(&params.PID[3].KD));

		read_4bytes((uint32_t*)(&params.tilt_roll_offset));
		read_4bytes((uint32_t*)(&params.tilt_pitch_offset));
		read_4bytes((uint32_t*)(&params.tilt_yaw_offset));
		read_4bytes((uint32_t*)(&params.g_believe));

		read_4bytes((uint32_t*)(&params.gx_bias));
		read_4bytes((uint32_t*)(&params.gy_bias));
		read_4bytes((uint32_t*)(&params.gz_bias));

		read_4bytes((uint32_t*)(&params.ax_bias));
		read_4bytes((uint32_t*)(&params.ay_bias));
		read_4bytes((uint32_t*)(&params.az_bias));

		read_4bytes((uint32_t*)(&params.mx_bias));
		read_4bytes((uint32_t*)(&params.my_bias));
		read_4bytes((uint32_t*)(&params.mz_bias));

		read_4bytes((uint32_t*)(&params.mx_scale));
		read_4bytes((uint32_t*)(&params.my_scale));
		read_4bytes((uint32_t*)(&params.mz_scale));

		//MPC Load Params
		read_4bytes((uint32_t*)(&params.MPC_Cons_Ix));
		read_4bytes((uint32_t*)(&params.MPC_Cons_Iy));
		read_4bytes((uint32_t*)(&params.MPC_Cons_Iz));
		read_4bytes((uint32_t*)(&params.MPC_Cons_m));
		read_4bytes((uint32_t*)(&params.MPC_Cons_g));
		read_8bytes((uint64_t*)(&params.MPC_Cons_Jtp));
		read_4bytes((uint32_t*)(&params.MPC_Cons_Ts));

		read_4bytes((uint32_t*)(&params.MPC_Cons_ut));
		read_4bytes((uint32_t*)(&params.MPC_Cons_vt));
		read_4bytes((uint32_t*)(&params.MPC_Cons_wt));

		read_4bytes((uint32_t*)(&params.MPC_Cons_pt));
		read_4bytes((uint32_t*)(&params.MPC_Cons_qt));
		read_4bytes((uint32_t*)(&params.MPC_Cons_rt));

		read_4bytes((uint32_t*)(&params.MPC_Cons_xt));
		read_4bytes((uint32_t*)(&params.MPC_Cons_yt));
		read_4bytes((uint32_t*)(&params.MPC_Cons_zt));

		read_4bytes((uint32_t*)(&params.MPC_Cons_phit));
		read_4bytes((uint32_t*)(&params.MPC_Cons_thetat));
		read_4bytes((uint32_t*)(&params.MPC_Cons_psit));

		read_4bytes((uint32_t*)(&params.MPC_Cons_omega1));
		read_4bytes((uint32_t*)(&params.MPC_Cons_omega2));
		read_4bytes((uint32_t*)(&params.MPC_Cons_omega3));
		read_4bytes((uint32_t*)(&params.MPC_Cons_omega4));

		unsigned char i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_Q[i][j]));
			}
		}
		i=0;j=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_S[i][j]));
			}
		}
		i=0;j=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_R[i][j]));
			}
		}

		read_8bytes((uint64_t*)(&params.MPC_Cons_ct));
		read_8bytes((uint64_t*)(&params.MPC_Cons_cq));
		read_4bytes((uint32_t*)(&params.MPC_Cons_l));
		read_1byte((uint8_t*)(&params.MPC_Cons_controlled_states));
		read_1byte((uint8_t*)(&params.MPC_Cons_hz));
		read_1byte((uint8_t*)(&params.MPC_Cons_innerDyn_length));

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_px[i][j]));
			}
		}

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_py[i][j]));
			}
		}

		i=0;j=0;
		for(i=0;i<1;i++){
			for(j=0;j<2;j++){
				read_1byte((uint8_t*)(&params.MPC_Cons_pz[i][j]));
			}
		}

		read_1byte((uint8_t*)(&params.MPC_Cons_r));
		read_4bytes((uint32_t*)(&params.MPC_Cons_f));
		read_1byte((uint8_t*)(&params.MPC_Cons_height_i));
		read_1byte((uint8_t*)(&params.MPC_Cons_height_f));
		read_4bytes((uint32_t*)(&params.MPC_Cons_drag_switch));
		read_4bytes((uint32_t*)(&params.MPC_Cons_C_D_u));
		read_4bytes((uint32_t*)(&params.MPC_Cons_C_D_v));
		read_4bytes((uint32_t*)(&params.MPC_Cons_C_D_w));
		read_4bytes((uint32_t*)(&params.MPC_Cons_A_u));
		read_4bytes((uint32_t*)(&params.MPC_Cons_A_v));
		read_4bytes((uint32_t*)(&params.MPC_Cons_A_w));
		read_4bytes((uint32_t*)(&params.MPC_Cons_Sub_loop));
		read_4bytes((uint32_t*)(&params.MPC_Cons_rho));
		read_1byte((uint8_t*)(&params.MPC_Cons_trajectory));

		return true;
}

