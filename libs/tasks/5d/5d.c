//
// Created by user on 15.02.2022.
//

#include "5d.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <stdio.h>

#define MEM_NULL_CHECK(mem) \
    if(NULL == mem) raise("bad allocation")

static void raise(const char *const error) {
    fprintf(stderr, "%s\n", error);
    exit(1);
}
static int max2(const int x, const int y) {
    return x > y ? x : y;
}

static int min2(const int x, const int y) {
    return x < y ? x : y;
}

static int getMax(const int *const a, const int size) {
    int max = a[0];
    for (int i = 1; i < size; ++i)
        max = max2(max, a[i]);

    return max;
}

static int getMin(const int *const a, const int size) {
    int min = a[0];
    for (int i = 1; i < size; ++i)
        min = min2(min, a[i]);

    return min;
}

static long long getSum(const int *const a, const int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += a[i];

    return sum;
}

static float getDistance(const int *const a, const int size) {
    long long distanceSquared = 0;
    for (int i = 0; i < size; ++i)
        distanceSquared += a[i] * a[i];

    return sqrt(distanceSquared);
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

int countNUnique(const long long *const a, const int size) {
    if (size == 0)
        return 0;

    long long *aCopy = (long long *) malloc(size * sizeof(long long));
    memcpy(aCopy, a, size * sizeof(long long));
    qsort(aCopy, size, sizeof(long long), long_long_cmp);

    int counter = 1;
    for (int i = 1; i < size; ++i)
        if (aCopy[i - 1] != aCopy[i])
            counter++;

    return counter;
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

long long findSumOfMaxesOfPseudoDiagonal(const matrix m) {
    long long sum = 0;

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 1; i < rows; ++i) {
        int j = 0;
        int k = i;
        int max = m.values[k][j];
        while (k < rows && j < cols)
            max = max2(max, m.values[k++][j++]);
        sum += max;
    }
    for (int j = 1; j < cols; ++j) {
        int i = 0;
        int k = j;
        int max = m.values[i][k];
        while (i < rows && k < cols)
            max = max2(max, m.values[i++][k++]);
        sum += max;
    }

    return sum;
}

int getMinInArea(const matrix m) {
    position pos = getMaxValuePos(m);
    int rowIndex = pos.rowIndex;
    int leftBoarder = pos.colIndex;
    int rightBoarder = leftBoarder;
    int min = m.values[rowIndex][leftBoarder];

    while (rowIndex >= 0) {
        for (int k = leftBoarder; k <= rightBoarder; ++k)
            min = min2(min, m.values[rowIndex][k]);
        if (leftBoarder > 0)
            leftBoarder--;
        if (rightBoarder + 1 < m.nCols)
            rightBoarder++;
        rowIndex--;
    }

    return min;
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int countEqClassesByRowsSum(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    long long *arrayOfSums = (long long *) malloc(sizeof(long long) * rows);

    MEM_NULL_CHECK(arrayOfSums);

    for (int i = 0; i < rows; ++i)
        arrayOfSums[i] = getSum(m.values[i], cols);

    int unique = countNUnique(arrayOfSums, rows);

    free(arrayOfSums);

    return unique;
}

int getNSpecialElement(const matrix m) {
    int counter = 0;

    for (int i = 0; i < m.nCols; ++i) {
        long long currentSum = 0;
        for (int j = 0; j < m.nRows; ++j)
            currentSum += m.values[j][i];
        for (int j = 0; j < m.nRows; ++j)
            if (currentSum < 2 * m.values[j][i])
                counter++;
    }

    return counter;
}
