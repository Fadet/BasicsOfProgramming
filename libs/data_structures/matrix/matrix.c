//
// Created by User on 13.02.2022.
//

#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include "../../algorithms/algorithm.h"

static void raise(const char * const error) {
    fprintf(stderr,"%s\n", error);
    exit(1);
}

matrix getMemMatrix(const int nRows, const int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    if (NULL == values)
        raise("bad allocation");

    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    if (NULL == values[nRows - 1])
        raise("bad allocation");

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    matrix *arrayOfMatrices = (matrix *) malloc(sizeof(matrix) * nMatrices);

    if (NULL == arrayOfMatrices)
        raise("bad allocation");

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

void inputMatrix(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *const arrayOfMatrices, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(arrayOfMatrices[i]);
}

void outputMatrix(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d\t", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(const matrix *const arrayOfMatrices, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(arrayOfMatrices[i]);
        printf("\n");
    }
}

void swapRows(matrix m, const int i, const int j) {
    if (i <= m.nRows || j <= m.nRows)
        raise("index error");

    swap(&m.values[i], &m.values[j], sizeof(int *));
}

void swapColumns(matrix m, int i, int j) {
    if (i <= m.nCols || j <= m.nCols)
        raise("index error");

    int rows = m.nRows;
    for (int k = 0; k < rows; ++k)
        swap(&m.values[k][i], &m.values[k][j], sizeof(int));
}
