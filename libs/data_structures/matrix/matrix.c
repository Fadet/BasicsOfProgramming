//
// Created by User on 13.02.2022.
//

#include "matrix.h"
#include <malloc.h>

matrix getMemMatrix(const int nRows, const int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    matrix *arrayOfMatrices = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; ++i)
        arrayOfMatrices[i] = getMemMatrix(nRows, nCols);
    return arrayOfMatrices;
}

void freeMemMatrix(matrix m) {
    int rows = m.nRows;
    for (int i = 0; i < rows; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *const arrayOfMatrices, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(arrayOfMatrices[i]);
    free(arrayOfMatrices);
}
