/*
 * mpc_simplification.h
 *
 *  Created on: Jun 27, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_MPC_SIMPLIFICATION_MPC_SIMPLIFICATION_H_
#define APPLICATION_MPC_MPC_SIMPLIFICATION_MPC_SIMPLIFICATION_H_

int mpc_simplification(double Ad_matrix[6][6],double Bd_matrix[6][3],double Cd_matrix[3][6], double Dd_matrix[3][3],int *hz,double Hdb_r_4hz[12][12],double Fdbt_r_4hz[21][12],double Hdb_r_3hz[9][9],double Fdbt_r_3hz[18][9],double Hdb_r_2hz[6][6],double Fdbt_r_2hz[15][6],double Hdb_r_1hz[3][3],double Fdbt_r_1hz[12][6]);

#endif /* APPLICATION_MPC_MPC_SIMPLIFICATION_MPC_SIMPLIFICATION_H_ */
