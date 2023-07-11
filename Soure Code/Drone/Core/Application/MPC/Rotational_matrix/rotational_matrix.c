/*
 * rotational_matrix.c
 *
 *  Created on: May 27, 2023
 *      Author: nguye
 *      Rotational matrix that relates u,v,w with x_dot,y_dot,z_dot
 */
#include "rotational_matrix.h"
#include "params.h"
#include "user_define.h"
#include <math.h>

//Rotational matrix that relates u,v,w with x_dot,y_dot,z_dot
int get_rotational_matrix_pos_controller(double R_matrix[3][3], double *state_u, double *state_v, double *state_w, double *state_phi, double *state_theta, double *state_psi, double *x_dot, double *y_dot, double *z_dot){
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t k = 0;
	double Rx[3][3],Ry[3][3],Rz[3][3];
	double RyRx[3][3];
	double pos_vel_body[3];
	double pos_vel_fixed[3];
	double phi,theta,psi;
#if BNO055_EULER_ANGLES_UNITS == 0
	/*Convert Degree to Radian*/
	phi = *roll*(M_PI/180);
	theta = *pitch*(M_PI/180);
	psi = *yaw*(M_PI/180);
#elif BNO055_EULER_ANGLES_UNITS == 1
	phi = *state_phi;
	theta = *state_theta;
	psi = *state_psi;
#endif
	/*Init Rx Matrix*/
	Rx[0][0] = 1; Rx[0][1] = 0; Rx[0][2] = 0;
	Rx[1][0] = 0; Rx[1][1] = cos(phi); Rx[1][2] = sin(phi);
	Rx[2][0] = 0; Rx[2][1] = -sin(phi); Rx[2][2] = cos(phi);
	/*Init Ry Matrix*/
	Ry[0][0] = cos(theta); Ry[0][1] = 0; Ry[0][2] = -sin(theta);
	Ry[1][0] = 0; Ry[1][1] = 1; Ry[1][2] = 0;
	Ry[2][0] = sin(theta); Ry[2][1] = 0; Ry[2][2] = cos(theta);
	/*Init Rz Matrix*/
	Ry[0][0] = cos(psi); Ry[0][1] = -sin(psi); Ry[0][2] = 0;
	Ry[1][0] = sin(psi); Ry[1][1] = cos(psi); Ry[1][2] = 0;
	Ry[2][0] = 0; Ry[2][1] = 0; Ry[2][2] = 1;
	/*Calculation for R_matrix*/
	// Calculation for RyRx matrix by multiplication
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			RyRx[i][j] = 0;
			for(k=0;k<3;k++){
				RyRx[i][j] += Ry[i][k] * Rx[k][i];
			}
		}
	}
	// Calculation for R Rotation matrix by multiplication Rz & RyRx
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			R_matrix[i][j] = 0;
			for(k=0;k<3;k++){
				R_matrix[i][j] += Rz[i][k] * RyRx[k][i];
			}
		}
	}
	/*Create pos_vel_body*/
	//vector for the linear velocities in the body frame V vector B = [ u v w ]T m/s
	pos_vel_body[0] = *state_u;
	pos_vel_body[1] = *state_v;
	pos_vel_body[2] = *state_w;
	/* Connect the linear velocities on the inertia frame to the linear velocities in the body frame*/
	pos_vel_fixed[0] = R_matrix[0][0]*pos_vel_body[0] + R_matrix[0][1]*pos_vel_body[1] + R_matrix[0][2]*pos_vel_body[2];
	pos_vel_fixed[1] = R_matrix[1][0]*pos_vel_body[0] + R_matrix[1][1]*pos_vel_body[1] + R_matrix[1][2]*pos_vel_body[2];
	pos_vel_fixed[2] = R_matrix[2][0]*pos_vel_body[0] + R_matrix[2][1]*pos_vel_body[1] + R_matrix[2][2]*pos_vel_body[2];
	/* Compute the Error*/
	*x_dot = pos_vel_fixed[0];
	*y_dot = pos_vel_fixed[1];
	*z_dot = pos_vel_fixed[2];
	return 0;
}

int get_rotational_matrix_lpv_cont_discrete(double *roll, double *pitch,double *yaw, double R_matrix[3][3],double T_maxtrix[3][3],double *state_u,double *state_v,double *state_w,double *state_p,double *state_q,double *state_r, double *x_dot, double *y_dot, double *z_dot){
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t k = 0;
	double Rx[3][3],Ry[3][3],Rz[3][3];
	double RyRx[3][3];
	double pos_vel_body[3],pos_vel_fixed[3];
	double phi,theta,psi;
#if BNO055_EULER_ANGLES_UNITS == 0
	/*Convert Degree to Radian*/
	phi = *roll*(M_PI/180);
	theta = *pitch*(M_PI/180);
	psi = *yaw*(M_PI/180);
#elif BNO055_EULER_ANGLES_UNITS == 1
	phi = *roll;
	theta = *pitch;
	psi = *yaw;
#endif
	/*Init Rx Matrix*/
	Rx[0][0] = 1; Rx[0][1] = 0; Rx[0][2] = 0;
	Rx[1][0] = 0; Rx[1][1] = cos(phi); Rx[1][2] = sin(phi);
	Rx[2][0] = 0; Rx[2][1] = -sin(phi); Rx[2][2] = cos(phi);
	/*Init Ry Matrix*/
	Ry[0][0] = cos(theta); Ry[0][1] = 0; Ry[0][2] = -sin(theta);
	Ry[1][0] = 0; Ry[1][1] = 1; Ry[1][2] = 0;
	Ry[2][0] = sin(theta); Ry[2][1] = 0; Ry[2][2] = cos(theta);
	/*Init Rz Matrix*/
	Ry[0][0] = cos(psi); Ry[0][1] = -sin(psi); Ry[0][2] = 0;
	Ry[1][0] = sin(psi); Ry[1][1] = cos(psi); Ry[1][2] = 0;
	Ry[2][0] = 0; Ry[2][1] = 0; Ry[2][2] = 1;
	/*Calculation for R_matrix*/
	// Calculation for RyRx matrix by multiplication
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			RyRx[i][j] = 0;
			for(k=0;k<3;k++){
				RyRx[i][j] += Ry[i][k] * Rx[k][i];
			}
		}
	}
	// Calculation for R Rotation matrix by multiplication Rz & RyRx
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			R_matrix[i][j] = 0;
			for(k=0;k<3;k++){
				R_matrix[i][j] += Rz[i][k] * RyRx[k][i];
			}
		}
	}
	/*Create pos_vel_body*/
	//vector for the linear velocities in the body frame V vector B = [ u v w ]T m/s
	pos_vel_body[0] = *state_u;
	pos_vel_body[1] = *state_v;
	pos_vel_body[2] = *state_w;
	/* Connect the linear velocities on the inertia frame to the linear velocities in the body frame*/
	pos_vel_fixed[0] = R_matrix[0][0]*pos_vel_body[0] + R_matrix[0][1]*pos_vel_body[1] + R_matrix[0][2]*pos_vel_body[2];
	pos_vel_fixed[1] = R_matrix[1][0]*pos_vel_body[0] + R_matrix[1][1]*pos_vel_body[1] + R_matrix[1][2]*pos_vel_body[2];
	pos_vel_fixed[2] = R_matrix[2][0]*pos_vel_body[0] + R_matrix[2][1]*pos_vel_body[1] + R_matrix[2][2]*pos_vel_body[2];
	*x_dot = pos_vel_fixed[0];
	*y_dot = pos_vel_fixed[1];
	*z_dot = pos_vel_fixed[2];
	/*To get phi_dot, theta_dot, psi_dot, you need the T matrix*/
	//Transformation matrix that relates p,q,r with phi_dot,theta_dot,psi_dot
	/* Transpose Rotation Matrix*/
	T_maxtrix[0][0] = 1; T_maxtrix[0][1] = sin(phi)*tan(theta); T_maxtrix[0][2] = cos(phi)*tan(theta);
	T_maxtrix[1][0] = 0; T_maxtrix[1][1] = cos(phi); T_maxtrix[1][2] = -sin(phi);
	T_maxtrix[2][0] = 0; T_maxtrix[2][1] = sin(phi)/cos(theta); T_maxtrix[2][2] = cos(phi)/cos(theta);
	return 0;
}

