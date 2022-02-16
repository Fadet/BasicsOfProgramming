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

#endif //LABS_LIBS_5D_H
