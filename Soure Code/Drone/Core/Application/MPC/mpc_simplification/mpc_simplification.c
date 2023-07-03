/*
 * mpc_simplification.c
 *
 *  Created on: Jun 27, 2023
 *      Author: nguye
 */

#include "params.h"
#include "../Rotational_matrix/rotational_matrix.h"
#include "../Matrix_calculation/matrix.h"
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../LPV_cont_discrete/LPV_cont_discrete.h"

int mpc_simplification(double Ad_matrix[6][6],double Bd_matrix[6][3],double Cd_matrix[3][6], double Dd_matrix[3][3],int *hz){
    /*This function creates the compact matrices for Model Predictive Control*/
	// db - double bar
	// dbt - double bar transpose
	// dc - double circumflex

	/*Create A_aug*/
	//A_aug=np.concatenate((Ad,Bd),axis=1)
	double A_aug[6][9];
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			A_aug[i][j] = Ad_matrix[i][j];
		}
	}
	for(int i=0;i<6;i++){
		for(int j=6;j<9;j++){
			A_aug[i][j] = Bd_matrix[i][j-6];
		}
	}
	float temp_A[3][9] = {
	        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0},
	        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
	        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}
	};
	//A_aug=np.concatenate((A_aug,temp),axis=0)
	double A_aug_matrixpower[9][9];
	double A_aug_matrixpower_B_aug[9][3];
	double A_aug_new[9][9];
	for(int i=0;i<6;i++){
		for(int j=0;j<9;j++){
			A_aug_new[i][j] = A_aug[i][j];
		}
	}
	for(int i=6;i<9;i++){
		for(int j=0;j<9;j++){
			A_aug_new[i][j] = temp_A[i-6][j];
		}
	}
	/*Create B_aug*/
	float temp_B[3][3] = {
		 {1.0, 0.0, 0.0},
		 {0.0, 1.0, 0.0},
		 {0.0, 0.0, 1.0}
	};
	double B_aug[9][3];
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			B_aug[i][j] = Bd_matrix[i][j];
		}
	}
	for(int i=6;i<9;i++){
		for(int j=0;j<3;j++){
			B_aug[i][j] = temp_B[i-6][j];
		}
	}
	/*Create C_aug*/
	float temp_C[3][3]={
			{0.0, 0.0, 0.0},
			{0.0, 0.0, 0.0},
			{0.0, 0.0, 0.0}
	};
	double C_aug[3][9];
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			C_aug[i][j] = Cd_matrix[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=6;j<9;j++){
			C_aug[i][j] = temp_C[i][j-6];
		}
	}
	/*Create D_aug*/
	double D_aug[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			D_aug[i][j] = Dd_matrix[i][j];
		}
	}
	/*Calculation for CQC,CSC,QC,SC Matrix*/
	//transpose C_aug
	float C_aug_transpose[9][3];
	C_aug_transpose[0][0] = C_aug[0][0];	C_aug_transpose[0][1] = C_aug[1][0]; C_aug_transpose[0][2] = C_aug[2][0];
	C_aug_transpose[1][0] = C_aug[0][1];	C_aug_transpose[1][1] = C_aug[1][1]; C_aug_transpose[1][2] = C_aug[2][1];
	C_aug_transpose[2][0] = C_aug[0][2];	C_aug_transpose[2][1] = C_aug[1][2]; C_aug_transpose[2][2] = C_aug[2][2];
	C_aug_transpose[3][0] = C_aug[0][3];	C_aug_transpose[3][1] = C_aug[1][3]; C_aug_transpose[3][2] = C_aug[2][3];
	C_aug_transpose[4][0] = C_aug[0][4];	C_aug_transpose[4][1] = C_aug[1][4]; C_aug_transpose[4][2] = C_aug[2][4];
	C_aug_transpose[5][0] = C_aug[0][5];	C_aug_transpose[5][1] = C_aug[1][5]; C_aug_transpose[5][2] = C_aug[2][5];
	C_aug_transpose[6][0] = C_aug[0][6];	C_aug_transpose[6][1] = C_aug[1][6]; C_aug_transpose[6][2] = C_aug[2][6];
	C_aug_transpose[7][0] = C_aug[0][7];	C_aug_transpose[7][1] = C_aug[1][7]; C_aug_transpose[7][2] = C_aug[2][7];
	C_aug_transpose[8][0] = C_aug[0][8];	C_aug_transpose[8][1] = C_aug[1][8]; C_aug_transpose[8][2] = C_aug[2][8];

	//CQC=np.matmul(np.transpose(C_aug),Q)
	float C_aug_matmul_Q[9][3]={0};
	for(int i=0;i<9;i++){
		for(int j=0;j<3;j++){
			C_aug_matmul_Q[i][j] = 0.0;
			for(int k=0;k<3;k++){
				C_aug_matmul_Q[i][j] += C_aug_transpose[i][k]*params.MPC_Cons_Q[k][j];
			}
		}
	}
	//CQC=np.matmul(CQC,C_aug)
	float CQC[9][9]={0};
    for (int i=0;i<9; i++) {
        for (int j=0;j<9; j++) {
        	CQC[i][j] = 0;
            for (int k=0; k<3; k++) {
            	CQC[i][j] += C_aug_matmul_Q[i][k] * C_aug[k][j];
            }
        }
    }
    //CSC=np.matmul(np.transpose(C_aug),S)
	float C_aug_matmul_S[9][3]={0};
	for(int i=0;i<9;i++){
		for(int j=0;j<3;j++){
			C_aug_matmul_S[i][j] = 0.0;
			for(int k=0;k<3;k++){
				C_aug_matmul_S[i][j] += C_aug_transpose[i][k]*params.MPC_Cons_S[k][j];
			}
		}
	}
	//CSC=np.matmul(C_aug_matmul_S,C_aug)
	float CSC[9][9]={0};
    for (int i=0;i<9; i++) {
        for (int j=0;j<9; j++) {
        	CSC[i][j] = 0;
            for (int k=0; k<3; k++) {
            	CSC[i][j] += C_aug_matmul_S[i][k] * C_aug[k][j];
            }
        }
    }
    //QC=np.matmul(Q,C_aug)
	float QC[3][9]={0.0};
    for (int i=0;i<3;i++) {
        for (int j=0;j<9;j++) {
        	QC[i][j] = 0;
            for (int k=0;k<3;k++) {
            	QC[i][j] += params.MPC_Cons_Q[i][k] * C_aug[k][j];
            }
        }
    }
    //SC=np.matmul(S,C_aug)
	float SC[3][9]={0.0};
    for (int i=0;i<3;i++) {
        for (int j=0;j<9;j++) {
        	SC[i][j] = 0;
            for (int k=0;k<3;k++) {
            	SC[i][j] += params.MPC_Cons_S[i][k] * C_aug[k][j];
            }
        }
    }
    //calculation rows and columns of CQC
    int CQC_rows = sizeof(CQC) / sizeof(CQC[0]);
    int CQC_columns = sizeof(CQC[0]) / sizeof(CQC[0][0]);
    //calculation rows and columns of QC
    int QC_rows = sizeof(QC) / sizeof(QC[0]);
    int QC_columns = sizeof(QC[0]) / sizeof(QC[0][0]);
    //calculation rows and columns of SC
    int SC_rows = sizeof(SC) / sizeof(SC[0]);
    int SC_columns = sizeof(SC[0]) / sizeof(SC[0][0]);
    //calculation rows and columns of R
    int R_rows = 3;
    int R_columns = 3;
    //calculation rows and columns of B_aug
    int B_aug_rows = sizeof(B_aug) / sizeof(B_aug[0]);
    int B_aug_columns = sizeof(B_aug[0]) / sizeof(B_aug[0][0]);
    /*Create for Qdb,Tdb,Rdb,Cdb,Adc Matrix which following hz*/
    int hz_t = *hz;
	if(hz_t == 1){
		float Qdb[9][9] = {0}; float Tdb[3][9] = {0}; float Rdb[3][3] = {0}; float Cdb[9][3] = {0}; float Adc[9][9] = {0};
	}
	else if (hz_t == 2){
		float Qdb[18][18] = {0}; float Tdb[6][18] = {0}; float Rdb[6][6] = {0}; float Cdb[18][6] = {0}; float Adc[18][9] = {0};
	}
	else if (hz_t == 3){
		float Qdb[27][27] = {0}; float Tdb[9][27] = {0}; float Rdb[9][9] = {0}; float Cdb[27][9] = {0};  float Adc[27][9]={0};
	}
	else{
		float Qdb[36][36] = {0}; float Tdb[12][36] = {0}; float Rdb[12][12] = {0}; float Cdb[36][12] = {0};  float Adc[36][9]={0};
		/*Calculation for Hdb,Fdbt,Cdb,Adc Matrix with hz=4*/
		for(int hz_i=0;hz_i<hz_t;hz_i++){
			if(hz_i==hz_t-1){
			/*Qdb*/
				int Qdb_rows_start = CQC_rows*hz_i; int Qdb_rows_end = CQC_rows*hz_i+CQC_rows;
				int Qdb_columns_start = CQC_columns*hz_i; int Qdb_columns_end = CQC_columns*hz_i+CQC_columns;
				//insert columns of CQC to Qdb
				int j,k,l,m;
				for(j=Qdb_rows_start,k=0;j<Qdb_rows_end;j++,k++){
					for(l=Qdb_columns_start,m=0;l<Qdb_columns_end;l++,m++){
						Qdb[j][l] = CQC[k][m];
					}
				}
			/*Tdb*/
				int Tdb_rows_start = SC_rows*hz_i; int Tdb_rows_end = SC_rows*hz_i+SC_rows;
				int Tdb_columns_start = SC_columns*hz_i; int Tdb_columns_end = SC_columns*hz_i+SC_columns;
				for(j=Tdb_rows_start,k=0;j<Tdb_rows_end;j++,k++){
					for(l=Tdb_columns_start,m=0;l<Tdb_columns_end;l++,m++){
						Tdb[j][l] = SC[k][m];
					}
				}
			}
			else{
			/*Qdb*/
				int Qdb_rows_start = CQC_rows*hz_i; int Qdb_rows_end = CQC_rows*hz_i+CQC_rows;
				int Qdb_columns_start = CQC_columns*hz_i; int Qdb_columns_end = CQC_columns*hz_i+CQC_columns;
				//insert columns of CQC to Qdb
				int j,k,l,m;
				for(j=Qdb_rows_start,k=0;j<Qdb_rows_end;j++,k++){
					for(l=Qdb_columns_start,m=0;l<Qdb_columns_end;l++,m++){
						Qdb[j][l] = CQC[k][m];
					}
				}
		    /*Tdb*/
				int Tdb_rows_start = QC_rows*hz_i; int Tdb_rows_end = QC_rows*hz_i+QC_rows;
				int Tdb_columns_start = QC_columns*hz_i; int Tdb_columns_end = QC_columns*hz_i+QC_columns;
				for(j=Tdb_rows_start,k=0;j<Tdb_rows_end;j++,k++){
					for(l=Tdb_columns_start,m=0;l<Tdb_columns_end;l++,m++){
						Tdb[j][l] = QC[k][m];
					}
				}
			}
			/*Rdb*/
			int j,k,l,m;
			int Rdb_rows_start = R_rows*hz_i; int Rdb_rows_end = R_rows*hz_i+R_rows;
			int Rdb_columns_start = R_columns*hz_i; int Rdb_columns_end = R_columns*hz_i+R_columns;
			for(j=Rdb_rows_start,k=0;j<Rdb_rows_end;j++,k++){
				for(l=Rdb_columns_start,m=0;l<Rdb_columns_end;l++,m++){
					Rdb[j][l] = params.MPC_Cons_R[k][m];
				}
			}
			for(int hz_j=0;hz_j<hz_t;hz_j++){
				if(hz_j<=hz_i){
			    /*Cdb*/
				int j,k,l,m;
				int Cdb_rows_start = B_aug_rows*hz_i; int Cdb_rows_end = B_aug_rows*hz_i+R_rows;
				int Cdb_columns_start = B_aug_columns*hz_i; int Cdb_columns_end = B_aug_columns*hz_i+B_aug_columns;
				int n=(hz_i+1)-(hz_j+1);
				//matrix power
				matrixPower(A_aug_new, &n, A_aug_matrixpower);
				//Calculation for A_aug_matrixpower with B_aug matrix by multiplication
				for(int i_mul=0;i_mul<9;i_mul++){
					for(int j_mul=0;j_mul<3;j_mul++){
						A_aug_matrixpower_B_aug[i_mul][j_mul] = 0;
						for(int k_mul=0;k_mul<9;k_mul++){
							A_aug_matrixpower_B_aug[i_mul][j_mul] += A_aug_matrixpower[i_mul][k_mul] * B_aug[k_mul][i_mul];
						}
					}
				}
				//Calculation Cdb
				for(j=Cdb_rows_start,k=0;j<Cdb_rows_end;j++,k++){
					for(l=Cdb_columns_start,m=0;l<Cdb_columns_end;l++,m++){
						Cdb[j][l] = A_aug_matrixpower_B_aug[k][m];
					}
				}
			    }
			}
			/*Adc*/
		}
	}
    return 0;
}