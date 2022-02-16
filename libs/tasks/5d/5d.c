//
// Created by user on 15.02.2022.
//

#include "5d.h"
#include <stdlib.h>
#include <memory.h>

static int max2(const int x, const int y) {
    return x > y ? x : y;
}

static int getMax(const int *const a, const int size) {
    int max = a[0];
    for (int i = 0; i < size; ++i)
        max = max2(max, a[i]);

    return max;
}

static int getMin(const int *const a, const int size) {
    int min = a[0];
    for (int i = 0; i < size; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

static long long getSum(const int *const a, const int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += a[i];

    return sum;
}

static int long_long_cmp(const void *x, const void *y) {
    long long a = *((long long *) x);
    long long b = *((long long *) y);

    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

static bool isUnique(const long long *const a, const int size) {
    long long *aCopy = (long long *) malloc(size * sizeof(long long));
    memcpy(aCopy, a, size * sizeof(long long));
    qsort(aCopy, size, sizeof(long long), long_long_cmp);

    for (int i = 1; i < size; ++i)
        if (aCopy[i - 1] == aCopy[i]) {
            free(aCopy);
            return false;
        }

    free(aCopy);
    return true;
}

void swapRowsWithMaxMinElements(matrix m) {
    position posMin = getMinValuePos(m);
    position posMax = getMaxValuePos(m);

    swapRows(m, posMin.rowIndex, posMax.rowIndex);
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void getSquareOfMatrixIfSymmetric(matrix *const m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix m_squared = multiplyMatrices(*m, *m);

    freeMemMatrix(*m);

    *m = m_squared;
}

void transposeIfMatrixDoesntHaveEqualSumOfRows(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    long long *sumsOfRows = (long long *) malloc(rows * sizeof(long long));

    for (int i = 0; i < rows; ++i)
        sumsOfRows[i] = getSum(m.values[i], cols);

    if (isUnique(sumsOfRows, rows))
        transposeSquareMatrix(m);

    free(sumsOfRows);
}

bool areMutuallyInverseMatrices(const matrix m1, const matrix m2) {
    matrix result = multiplyMatrices(m1, m2);

    if (isEMatrix(result)) {
        freeMemMatrix(result);
        return true;
    }
    freeMemMatrix(result);
    return false;
}
