//
// Created by User on 13.02.2022.
//

#include "matrix-test.h"
#include "../matrix.h"
#include "../../../algorithms/array/array.h"
#include <assert.h>
#include <malloc.h>

static void test_getMemMatrix_CommonCase() {
    matrix m = getMemMatrix(3, 4);

    assert(NULL != m.values);
    assert(m.nRows == 3);
    assert(m.nCols == 4);

    freeMemMatrix(m);
}

static void test_getMemMatrices_CommonCase() {
    matrix *matrices = getMemArrayOfMatrices(2, 2, 3);

    assert(NULL != matrices);
    assert(NULL != matrices[0].values);
    assert(matrices[0].nRows == 2);
    assert(matrices[0].nCols == 3);
    assert(NULL != matrices[1].values);
    assert(matrices[1].nRows == 2);
    assert(matrices[1].nCols == 3);

    freeMemMatrices(matrices, 2);
}

static void test_swapRows_swapTheSameRows() {
    matrix result = createMatrixFromArray((int []) {1, 2, 3,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);

    swapRows(result, 1, 1);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_swapRows_CommonCase() {
    matrix result = createMatrixFromArray((int []) {4, 5, 6,
                                                    1, 2, 3,
                                                    7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);

    swapRows(result,0, 1);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_swapColumns_swapTheSameCols() {
    matrix result = createMatrixFromArray((int []) {1, 2, 3,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);

    swapColumns(result, 1, 1);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_swapColumns_CommonCase() {
    matrix result = createMatrixFromArray((int []) {2, 1, 3,
                                                    5, 4, 6,
                                                    8, 7, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);

    swapColumns(result, 0, 1);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_insertionSortRowsMatrixByRowCriteria_sumOfRows() {
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);
    matrix result = createMatrixFromArray((int []) {7, 8, 9,
                                                    4, 5, 6,
                                                    1, 2, 3}, 3, 3);

    insertionSortRowsMatrixByRowCriteria(result, arraySum);

    assert(areTwoMatricesEqual(result, assumedMatrix));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_insertionSortColsMatrixByColCriteria_sumOfCols() {
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);
    matrix result = createMatrixFromArray((int []) {3, 2, 1,
                                                    6, 5, 4,
                                                    9, 8, 7}, 3, 3);

    insertionSortColsMatrixByColCriteria(result, arraySum);

    assert(areTwoMatricesEqual(result, assumedMatrix));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_areTwoMatricesEqual_equalMatrices() {
    matrix matrix1 = createMatrixFromArray((int []) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);
    matrix matrix2 = createMatrixFromArray((int []) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);

    assert(areTwoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

static void test_areTwoMatricesEqual_nonEqualMatrices() {
    matrix matrix1 = createMatrixFromArray((int []) {3, 2, 1,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);
    matrix matrix2 = createMatrixFromArray((int []) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);

    assert(!areTwoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

static void test_isSquareMatrix_squareMatrix() {
    matrix m = getMemMatrix(2, 2);

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

static void test_isSquareMatrix_nonSquareMatrix() {
    matrix m = getMemMatrix(3, 2);

    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

static void test_isEMatrix_identicalMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

static void test_isEMatrix_nonIdenticalMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

static void test_isEMatrix_nonSquareMatrix() {
    matrix m = getMemMatrix(2, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

static void test_isSymmetricMatrix_symmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 5,
                                              4, 2, 6,
                                              5, 6, 3}, 3, 3);

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

static void test_isSymmetricMatrix_nonSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 4,
                                              4, 2, 6,
                                              5, 6, 3}, 3, 3);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

static void test_isSymmetricMatrix_nonSquareMatrix() {
    matrix m = getMemMatrix(2, 3);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

static void test_transposeSquareMatrix_CommonCase() {
    matrix result = createMatrixFromArray((int []) {1, 2, 3,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int []) {1, 4, 7,
                                                           2, 5, 8,
                                                           3, 6, 9}, 3, 3);

    transposeSquareMatrix(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_getMinValuePos_CommonCase() {
    matrix m = createMatrixFromArray((int []) {3, 2, 1,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);

    position pos = getMinValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 2);

    freeMemMatrix(m);
}

static void test_getMinValuePos_matrixOfUnitDimension() {
    matrix m = createMatrixFromArray((int []) {10}, 1, 1);

    position pos = getMinValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 0);

    freeMemMatrix(m);
}

static void test_getMaxValuePos_CommonCase() {
    matrix m = createMatrixFromArray((int []) {3, 2, 1,
                                               4, 9, 6,
                                               7, 8, 5}, 3, 3);

    position pos = getMaxValuePos(m);

    assert(pos.rowIndex == 1);
    assert(pos.colIndex == 1);

    freeMemMatrix(m);
}

static void test_getMaxValuePos_matrixOfUnitDimension() {
    matrix m = createMatrixFromArray((int []) {10}, 1, 1);

    position pos = getMaxValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 0);

    freeMemMatrix(m);
}

static void test_createMatrixFromArray_commonCase() {
    int a[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};

    matrix m = createMatrixFromArray(a, 3, 3);

    int k = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j) {
            assert(m.values[i][j] == a[k]);
            k++;
        }

    freeMemMatrix(m);
}

static void test_createArrayOfMatricesFromArray_CommonCase() {
    int a[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9,
               10, 11, 12,
               13, 14, 15,
               16, 17, 18};

    matrix *am = createArrayOfMatricesFromArray(a, 2, 3, 3);

    int l = 0;
    for (int k = 0; k < 2; ++k)
        for (int i = 0; i < am[k].nRows; ++i)
            for (int j = 0; j < am[k].nCols; ++j) {
                assert(am[k].values[i][j] == a[l]);
                l++;
            }

    freeMemMatrices(am, 2);
}

void test_matrix() {
    test_getMemMatrix_CommonCase();
    test_getMemMatrices_CommonCase();
    test_createMatrixFromArray_commonCase();
    test_areTwoMatricesEqual_equalMatrices();
    test_areTwoMatricesEqual_nonEqualMatrices();
    test_swapRows_swapTheSameRows();
    test_swapRows_CommonCase();
    test_swapColumns_swapTheSameCols();
    test_swapColumns_CommonCase();
    test_insertionSortRowsMatrixByRowCriteria_sumOfRows();
    test_insertionSortColsMatrixByColCriteria_sumOfCols();
    test_isSquareMatrix_squareMatrix();
    test_isSquareMatrix_nonSquareMatrix();
    test_isEMatrix_identicalMatrix();
    test_isEMatrix_nonIdenticalMatrix();
    test_isEMatrix_nonSquareMatrix();
    test_isSymmetricMatrix_symmetricMatrix();
    test_isSymmetricMatrix_nonSymmetricMatrix();
    test_isSymmetricMatrix_nonSquareMatrix();
    test_transposeSquareMatrix_CommonCase();
    test_getMinValuePos_matrixOfUnitDimension();
    test_getMinValuePos_CommonCase();
    test_getMaxValuePos_matrixOfUnitDimension();
    test_getMaxValuePos_CommonCase();
    test_createArrayOfMatricesFromArray_CommonCase();
}
