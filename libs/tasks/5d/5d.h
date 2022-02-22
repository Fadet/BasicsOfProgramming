//
// Created by user on 15.02.2022.
//

#ifndef LABS_LIBS_5D_H
#define LABS_LIBS_5D_H

#include "../../data_structures/matrix/matrix.h"

// swaps matrix m rows that contain maximum and minimum elements
void swapRowsWithMaxMinElements(matrix m);

// sorts rows of matrix m by maximum value in a row
void sortRowsByMaxElement(matrix m);

// sorts columns of matrix m by minimum value in a column
void sortColsByMinElement(matrix m);

// replaces matrix *m by its square if the matrix is symmetric
void getSquareOfMatrixIfSymmetric(matrix *m);

// transposes matrix m if it contains rows with unique sums
void transposeIfMatrixDoesntHaveEqualSumOfRows(matrix m);

// returns true if matrices m1 and m2 are mutually inverse else returns false
bool areMutuallyInverseMatrices(matrix m1, matrix m2);

// returns sum of maximum values on pseudo diagonals in matrix m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

// returns a minimum element of matrix m in specific area
int getMinInArea(matrix m);

// sorts array of point m by their distance from origin
void sortByDistances(matrix m);

// returns an amount of rows that have unique sums in matrix m
int countEqClassesByRowsSum(matrix m);

// returns an amount of elements that are greater
// than all element in its column in matrix m
int getNSpecialElement(matrix m);

// replaces penultimate row of matrix m with first column
// that minimum element belongs
void replacePenultimateRow(matrix m);

// returns an amount of matrices from arrayOfMatrices of size nMatrices
// which rows sorted by non-decreasing
int countNonDecreasingRowsMatrices(const matrix *arrayOfMatrices, int nMatrix);

// prints matrices from arrayOfMatrices of size nMatrix
// that has maximum amount of zero rows
void printMatrixWithMaxZeroRows(const matrix *arrayOfMatrices, int nMatrix);

// prints matrices from arrayOfMatrices of size nMatrix
// that has the least normal value
void printMatrixWithTheLeastNormalValue(const matrix *arrayOfMatrices, int nMatrix);

#endif //LABS_LIBS_5D_H
