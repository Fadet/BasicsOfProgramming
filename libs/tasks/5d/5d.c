//
// Created by user on 15.02.2022.
//

#include "5d.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>

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

static double getDistance(const int *const a, const int size) {
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

static position getLeftMin(const matrix m) {
    position minPos = (position) {0, 0};

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int min = m.values[minPos.rowIndex][minPos.colIndex];
            if (j < minPos.colIndex && m.values[i][j] == min ||
                m.values[i][j] < min)
                minPos = (position) {i, j};
        }
    }

    return minPos;
}

static bool isNonDecreasingSorted(const int *const a, const int size) {
    for (int i = 1; i < size; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

static bool hasAllNonDecreasingRows(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;

    for (int i = 0; i < rows; ++i)
        if (!isNonDecreasingSorted(m.values[i], cols))
            return false;
    return true;
}

static int countValues(const int *const a, const int size, const int value) {
    int counter = 0;

    for (int i = 0; i < size; ++i)
        counter += a[i] == value;

    return counter;
}

static int countZeroRows(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    int counter = 0;

    for (int i = 0; i < rows; ++i)
        counter += countValues(m.values[i], cols, 0) == cols;

    return counter;
}

static void getMinMaxFromMatrix(const matrix m, int *min, int *max) {
    int rows = m.nRows;
    int cols = m.nCols;

    int minV = m.values[0][0];
    int maxV = minV;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int currentValue = m.values[i][j];
            minV = min2(minV, currentValue);
            maxV = max2(maxV, currentValue);
        }
    }
    *min = minV;
    *max = maxV;
}

static long long getScalarProduct(const int *const v1, const int *const v2, const int dimension) {
    long long result = 0;
    for (int i = 0; i < dimension; ++i)
        result += (long long) v1[i] * v2[i];
    return result;
}

static double getCosine(const int *const v1, const int *const v2, const int dimension) {
    return (double) getScalarProduct(v1, v2, dimension)
           / (getDistance(v1, dimension) * getDistance(v2, dimension));
}

static long long getScalarProductRowAndCol(const matrix m, const int i, const int j) {
    int rows = m.nRows;

    int *column = (int *) malloc(sizeof(int) * rows);
    for (int k = 0; k < rows; ++k)
        column[k] = m.values[k][j];

    long long result = getScalarProduct(m.values[i], column, m.nCols);

    free(column);

    return result;
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

void replacePenultimateRow(matrix m) {
    int minColIndex = getLeftMin(m).colIndex;
    int penultimateRow = m.nRows - 2;
    int rows = m.nRows;

    int *minCol = (int *) malloc(sizeof(int) * rows);

    MEM_NULL_CHECK(minCol);

    for (int i = 0; i < rows; ++i)
        minCol[i] = m.values[i][minColIndex];

    memcpy(m.values[penultimateRow], minCol, sizeof(int) * m.nCols);

    free(minCol);
}

int countNonDecreasingRowsMatrices(const matrix *const arrayOfMatrices, const int nMatrix) {
    int counter = 0;

    for (int i = 0; i < nMatrix; ++i)
        counter += hasAllNonDecreasingRows(arrayOfMatrices[i]);

    return counter;
}

void printMatrixWithMaxZeroRows(const matrix *const arrayOfMatrices, const int nMatrix) {
    int *zeroRowsInMatrices = (int *) malloc(sizeof(int) * nMatrix);

    MEM_NULL_CHECK(zeroRowsInMatrices);

    for (int i = 0; i < nMatrix; ++i)
        zeroRowsInMatrices[i] = countZeroRows(arrayOfMatrices[i]);

    int zeroRowsMax = getMax(zeroRowsInMatrices, nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        if (zeroRowsMax == zeroRowsInMatrices[i]) {
            outputMatrix(arrayOfMatrices[i]);
            printf("\n");
        }

    free(zeroRowsInMatrices);
}

void printMatrixWithTheLeastNormalValue(const matrix *const arrayOfMatrices, const int nMatrix) {
    int *normalValuesInMatrices = (int *) malloc(sizeof(int) * nMatrix);

    MEM_NULL_CHECK(normalValuesInMatrices);

    int minNormal = INT_MAX;
    for (int i = 0; i < nMatrix; ++i) {
        int min, max;
        getMinMaxFromMatrix(arrayOfMatrices[i], &min, &max);

        int currentNormal = -min > max ? -min : max;
        normalValuesInMatrices[i] = currentNormal;

        minNormal = min2(minNormal, currentNormal);
    }

    for (int i = 0; i < nMatrix; ++i)
        if (normalValuesInMatrices[i] == minNormal) {
            outputMatrix(arrayOfMatrices[i]);
            printf("\n");
        }

    free(normalValuesInMatrices);
}

int getNSpecialElement2(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;

    int counter = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            int currentValue = m.values[i][j];
            if ((j == 0 || getMax(m.values[i], j) < currentValue)
                && (j == cols - 1 || getMin(m.values[i] + j + 1, cols - j - 1) > currentValue))
                counter++;
        }

    return counter;
}

int getVectorIndexWithMaxAngle(const matrix m, const int *const v) {
    int rows = m.nRows;
    int dimension = m.nCols;

    int maxAngleIndex = -1;
    double maxAngleCos = 1;
    for (int i = 0; i < rows; ++i) {
        double currenCos = getCosine(m.values[i], v, dimension);
        if (currenCos < maxAngleCos) {
            maxAngleCos = currenCos;
            maxAngleIndex = i;
        }
    }

    return maxAngleIndex;
}

long long getSpecialScalarProduct(const matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);

    return getScalarProductRowAndCol(m, maxPos.rowIndex, minPos.colIndex);
}
