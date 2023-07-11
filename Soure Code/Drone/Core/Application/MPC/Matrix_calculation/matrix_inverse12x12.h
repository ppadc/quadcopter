/*
 * matrix_inverse12x12.h
 *
 *  Created on: Jul 12, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_MATRIX_CALCULATION_MATRIX_INVERSE12X12_H_
#define APPLICATION_MPC_MATRIX_CALCULATION_MATRIX_INVERSE12X12_H_

void matrix_invert_12x12(double a[12][12], int k);
double determinant(double a[12][12], int k);
void cofactor(double num[12][12], int f);
void transpose(double num[12][12], double fac[12][12], int r);

#endif /* APPLICATION_MPC_MATRIX_CALCULATION_MATRIX_INVERSE12X12_H_ */
