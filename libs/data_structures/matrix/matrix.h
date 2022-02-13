//
// Created by User on 13.02.2022.
//

#ifndef LABS_LIBS_MATRIX_H
#define LABS_LIBS_MATRIX_H

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

#endif //LABS_LIBS_MATRIX_H
