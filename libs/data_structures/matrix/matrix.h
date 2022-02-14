//
// Created by User on 13.02.2022.
//

#ifndef LABS_LIBS_MATRIX_H
#define LABS_LIBS_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// returns an empty matrix of size nRows * nCols
matrix getMemMatrix(int nRows, int nCols);

// returns an array of size nMatrices that contains matrices of size nRows * nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// frees the memory given to the matrix m
void freeMemMatrix(matrix m);

// frees the memory of the arrayOfMatrices of size nMatrices
void freeMemMatrices(matrix *arrayOfMatrices, int nMatrices);

// inputs values to matrix m
void inputMatrix(matrix m);

// inputs array arrayOfMatrices of size nMatrices
void inputMatrices(matrix *arrayOfMatrices, int nMatrices);

// prints matrix m to stdout
void outputMatrix(matrix m);

// prints array arrayOfMatrices of size nMatrices to stdout
void outputMatrices(const matrix *arrayOfMatrices, int nMatrices);

// swaps i-th and j-th rows of matrix m
void swapRows(matrix m, int i, int j);

// swaps i-th and j-th columns of matrix m
void swapColumns(matrix m, int i, int j);

// sorts rows of matrix m by a non-increasing value of criteria
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria) (int *, int));

// sorts columns of matrix m by a non-increasing value of criteria
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria) (int *, int));

// returns true if matrix m has equal amount of rows and columns else returns false
bool isSquareMatrix(matrix m);

// returns true if matrices m1 and m2 equal else returns false
bool twoMatricesEqual(matrix m1, matrix m2);

// returns true if matrix m is identity else returns false
bool isEMatrix(matrix m);

// returns true if matrix is symmetric else returns false
bool isSymmetricMatrix(matrix m);

#endif //LABS_LIBS_MATRIX_H
