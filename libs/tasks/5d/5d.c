//
// Created by user on 15.02.2022.
//

#include "5d.h"

static int getMax(const int *const a, const int size) {
    int max = a[0];
    for (int i = 0; i < size; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

static int getMin(const int *const a, const int size) {
    int min = a[0];
    for (int i = 0; i < size; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
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
