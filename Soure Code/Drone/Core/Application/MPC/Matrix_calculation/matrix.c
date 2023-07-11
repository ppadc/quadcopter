/*
 * matrix.c
 *
 *  Created on: Jul 1, 2023
 *      Author: nguye
 */

#include<stdio.h>
#include<math.h>
#include "matrix.h"

void matrixPower(double matrix[9][9], int *n, double result[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int k=0; k<*n; k++) {
        int temp[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                for (int x = 0; x < 9; x++) {
                    temp[i][j] += matrix[i][x] * result[x][j];
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                result[i][j] = temp[i][j];
            }
        }
    }
}



