/*
 * mpc.c
 *
 *  Created on: Jun 25, 2023
 *      Author: nguye
 */
#include "delay_us.h"
#include "params.h"
#include "../open_loop_new_states/open_loop_new_states.h"
#include "../posision_controller/posision_control.h"
#include "../trajectory/trajectory.h"
#include "../mpc_simplification/mpc_simplification.h"
#include "../LPV_cont_discrete/LPV_cont_discrete.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef APPLICATION_MPC_MPC_C_
#define APPLICATION_MPC_MPC_C_

float t[251]={0.0};
double X_ref[251]={0.0},X_dot_ref[251]={0.0},X_dot_dot_ref[251]={0.0};
double Y_ref[251]={0.0},Y_dot_ref[251]={0.0},Y_dot_dot_ref[251]={0.0};
double Z_ref[251]={0.0},Z_dot_ref[251]={0.0},Z_dot_dot_ref[251]={0.0};
double psi_ref[251]={0.0};
double ut,vt,wt,pt,qt,rt,xt,yt,zt,phit,thetat,psit;
double states[12];
short genr_t = 0;
short plotl,k;
float omega1,omega2,omega3,omega4;
double U1,U2,U3,U4;
double U1_callback, Phi_ref_callback, Theta_ref_callback;
double Phi_ref[5][1],Theta_ref[5][1],Psi_ref[5][1]={{0.0}},refSignals[15]={0.0};

static void LPV_technique(){
	/*Generate the refence signals*/
	//Generate time refence
	if(genr_t == 0){
		for(int i=1;i<251;i++){
			t[i] = t[i] + 0.4;
		}
		plotl = sizeof(t) / sizeof(t[0]);
		generate_trajectory(t,X_ref,X_dot_ref,X_dot_dot_ref,Y_ref,Y_dot_ref,Y_dot_dot_ref,Z_ref,Z_dot_ref,Z_dot_dot_ref,psi_ref);
		//Load the initial state vector
		ut=params.MPC_Cons_ut; vt=params.MPC_Cons_vt; wt=params.MPC_Cons_wt;
		pt=params.MPC_Cons_pt; qt=params.MPC_Cons_qt; rt=params.MPC_Cons_rt;
		xt=params.MPC_Cons_xt; yt=params.MPC_Cons_yt; zt=params.MPC_Cons_zt;
		psi_ref[0]=params.MPC_Cons_psit;
		phit=params.MPC_Cons_phit; thetat=params.MPC_Cons_thetat; psit=params.MPC_Cons_psit;
		states[0] = ut; states[1] = vt; states[2] = wt;
		states[3] = pt; states[4] = qt; states[5] = rt;
		states[6] = xt; states[7] = yt; states[8] = zt;
		states[9] = phit; states[10] = thetat; states[11] = psit;

		/*Initial drone propeller states*/
		omega1 = params.MPC_Cons_omega1;
		omega2 = params.MPC_Cons_omega2;
		omega3 = params.MPC_Cons_omega3;
		omega4 = params.MPC_Cons_omega4;

		U1 = params.MPC_Cons_ct*(pow(omega1,2)+pow(omega2,2)+pow(omega3,2)+pow(omega4,2));
		U2 = params.MPC_Cons_ct*params.MPC_Cons_l*(pow(omega2,2)-pow(omega4,2));
		U3 = params.MPC_Cons_ct*params.MPC_Cons_l*(pow(omega3,2)-pow(omega1,2));
		U4 =  params.MPC_Cons_cq*(-pow(omega1,2)+pow(omega2,2)-pow(omega3,2)+pow(omega4,2));
	genr_t = 1;
	}
	/*Start the global controller*/
	for(int i_global=0;i_global<plotl-1;i_global++){
		/*outer loop*/
		pos_controller(&X_ref[i_global+1],&X_dot_ref[i_global+1],&X_dot_dot_ref[i_global+1],&Y_ref[i_global+1],&Y_dot_ref[i_global+1],&Y_dot_dot_ref[i_global+1],&Z_ref[i_global+1],&Z_dot_ref[i_global+1],&Z_dot_dot_ref[i_global+1],&psi_ref[i_global+1],&states[0],&states[1],&states[2],&states[6],&states[7],&states[8],&states[9],&states[10],&states[11],&U1_callback,&Phi_ref_callback,&Theta_ref_callback);
		//Create Phi_ref[5][1] &Theta_ref[5][1]
		for(int i=0;i<5;i++){
			Phi_ref[i][0] = Phi_ref_callback*1;
			Theta_ref[i][0] = Theta_ref_callback*1;
		}
		for(int yaw_step=0;yaw_step<params.MPC_Cons_innerDyn_length+1;yaw_step++){
			Psi_ref[yaw_step][0] = psi_ref[i_global]+((psi_ref[i_global+1]-psi_ref[i_global])/(params.MPC_Cons_Ts*params.MPC_Cons_innerDyn_length))*params.MPC_Cons_Ts*yaw_step;
		}
		//Create a reference vector
		int k=0;
		for(int i=0;i<15;i+=3){
			refSignals[i] = Phi_ref[k][0];
			refSignals[i+1] = Theta_ref[k][0];
			refSignals[i+2] = Psi_ref[k][0];
			k+=1;
		}
		k=0;
		for(int i=0;i<params.MPC_Cons_innerDyn_length;i++){

		}

	}
}


#endif /* APPLICATION_MPC_MPC_C_ */
