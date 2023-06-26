/*
 * posision_control.c
 *
 *  Created on: Jun 25, 2023
 *      Author: nguye
 */
#include "posision_control.h"
#include "params.h"
#include "../Rotational_matrix/rotational_matrix.h"
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int pos_controller(float *roll_t,float *pitch_t,float *yaw_t,float *X_ref,float *X_dot_ref,float *X_dot_dot_ref,float *Y_ref,float *Y_dot_ref,float *Y_dot_dot_ref,float *Z_ref,float *Z_dot_ref,float *Z_dot_dot_ref,float *Psi_ref,float *states_u,float *states_v,float *states_w,float *states_x,float *states_y,float *states_z,float *states_phi,float *states_theta,float *states_psi,double *U1_callback, double *Phi_ref_callback,double *Theta_ref_callback){
	float R_matrix_t[3][3];
	float euler_t[3],states_t[9];
	float x_dot_t,y_dot_t,z_dot_t;
	states_t[0] = *states_u; states_t[1] = *states_v; states_t[2] = *states_w;
	states_t[3] = *states_x; states_t[4] = *states_y; states_t[5] = *states_z;
	states_t[6] = *states_phi; states_t[7] = *states_theta; states_t[8] = *states_psi;
	get_rotational_matrix_pos_controller(&euler_t[0],&euler_t[1],&euler_t[2],R_matrix_t,&states_t[0],&states_t[1],&states_t[2],&x_dot_t,&y_dot_t,&z_dot_t);
	/*Compute the errors*/
	float ex,ey,ez,ex_dot,ey_dot,ez_dot;
	ex = *X_ref-states_t[3];
	ex_dot = *X_dot_ref-x_dot_t;
	ey = *Y_ref-states_t[4];
	ey_dot = *Y_dot_ref-y_dot_t;
	ez = *X_ref-states_t[5];
	ez_dot = *Z_dot_ref-z_dot_t;
	/*Compute the feedback constants*/
	float  complex kx1,kx2;
	float complex kx1_real, kx2_real;
	kx1 = (params.MPC_Cons_px[0][0]-pow(((params.MPC_Cons_px[0][0]+params.MPC_Cons_px[0][1])/2),2));
	kx1 -= pow(((params.MPC_Cons_px[0][0]+params.MPC_Cons_px[0][1])/4),2);
	kx2 = params.MPC_Cons_px[0][0]+params.MPC_Cons_px[0][1];
	kx1_real = creal(kx1);
	kx2_real = creal(kx2);

	float complex ky1,ky2;
	float complex ky1_real, ky2_real;
	ky1 = (params.MPC_Cons_py[0][0]-pow(((params.MPC_Cons_py[0][0]+params.MPC_Cons_py[0][1])/2),2));
	ky1 -= pow(((params.MPC_Cons_py[0][0]+params.MPC_Cons_py[0][1])/4),2);
	ky2 = params.MPC_Cons_py[0][0]+params.MPC_Cons_py[0][1];
	ky1_real = creal(ky1);
	ky2_real = creal(ky2);

	float complex kz1,kz2;
	float complex kz1_real, kz2_real;
	kz1 = (params.MPC_Cons_pz[0][0]-pow(((params.MPC_Cons_pz[0][0]+params.MPC_Cons_pz[0][1])/2),2));
	kz1 -= pow(((params.MPC_Cons_pz[0][0]+params.MPC_Cons_pz[0][1])/4),2);
	kz2 = params.MPC_Cons_pz[0][0]+params.MPC_Cons_pz[0][1];
	kz1_real = creal(kz1);
	kz2_real = creal(kz2);
	/*Compute the values vx, vy, vz for the position controller*/
	float ux, uy, uz;
	ux = kx1_real*ex+kx2_real*ex_dot;
	uy = ky1_real*ey+ky2_real*ey_dot;
	uz = kz1_real*ez+kz2_real*ey_dot;
	float vx, vy, vz;
	vx = *X_dot_dot_ref - ux;
	vy = *Y_dot_dot_ref - uy;
	vz = *Z_dot_dot_ref - uz;
	/*Compute phi, theta, U1*/
	float a,b,c,d,tan_theta;
	double Theta_ref;
	a = vx/(vz+params.MPC_Cons_g);
	b = vy/(vz+params.MPC_Cons_g);
	c = cos(*Psi_ref);
	d = sin(*Psi_ref);
	tan_theta = a*c+b*d;
	Theta_ref = atan(tan_theta);
	double Psi_ref_singularity,tan_phi;
	int floor;
	if(*Psi_ref>=0){
		floor = (abs(*Psi_ref)/(2*M_PI))*2*M_PI;
		Psi_ref_singularity = *Psi_ref-floor;
	}
	else{
		floor = (abs(*Psi_ref)/(2*M_PI))*2*M_PI;
		Psi_ref_singularity = *Psi_ref+floor;
	}
	if((abs(Psi_ref_singularity)<M_PI/4 || abs(Psi_ref_singularity)>7*M_PI/4) || (abs(Psi_ref_singularity)>3*M_PI/4 && abs(Psi_ref_singularity)<5*M_PI/4) ){
		tan_phi = cos(Theta_ref)*(tan(Theta_ref)*d-b)/c;
	}
	else{
		tan_phi = cos(Theta_ref)*(a-tan(Theta_ref)*c)/d;
	}
	double Phi_ref;
	Phi_ref = atan(tan_phi);
	*U1_callback =  (vz+params.MPC_Cons_g)*(params.MPC_Cons_m/cos(Phi_ref)*cos(Theta_ref));
	*Phi_ref_callback = Phi_ref;
	*Theta_ref_callback = Theta_ref;
	return 0;
}

