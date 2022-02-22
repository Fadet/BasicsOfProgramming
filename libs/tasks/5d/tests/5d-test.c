//
// Created by user on 15.02.2022.
//

#include "5d-test.h"
#include "../5d.h"
#include <assert.h>

static void test_swapRowsWithMaxMinElements_maxMinSameRow() {
    matrix result = createMatrixFromArray((int[]) {1, 2, 9,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 2, 9,
                                                          4, 5, 6,
                                                          7, 8, 9}, 3, 3);

    swapRowsWithMaxMinElements(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_swapRowsWithMaxMinElements_commonCase() {
    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                          4, 5, 6,
                                                          1, 2, 3}, 3, 3);

    swapRowsWithMaxMinElements(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortRowsByMaxElement_commonCase() {
    matrix result = createMatrixFromArray((int[]) {7, 1, 2,
                                                   1, 8, 1,
                                                   3, 2, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {3, 2, 3,
                                                          7, 1, 2,
                                                          1, 8, 1}, 3, 3);

    sortRowsByMaxElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortRowsByMaxElement_theSameMax() {
    matrix result = createMatrixFromArray((int[]) {7, 1, 2,
                                                   1, 7, 1,
                                                   7, 2, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {7, 1, 2,
                                                          1, 7, 1,
                                                          7, 2, 3}, 3, 3);

    sortRowsByMaxElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortColsByMinElement_commonCase() {
    matrix result = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                   2, 5, 1, 8, 2, 7,
                                                   6, 1, 4, 4, 8, 3}, 3, 6);
    matrix assumedMatrix = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                          5, 1, 2, 2, 7, 8,
                                                          1, 4, 6, 8, 3, 4}, 3, 6);

    sortColsByMinElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortColsByMinElement_theSameMin() {
    matrix result = createMatrixFromArray((int[]) {3, 5, 2, 4, 1, 1,
                                                   1, 5, 1, 1, 2, 7,
                                                   6, 1, 4, 4, 8, 3}, 3, 6);
    matrix assumedMatrix = createMatrixFromArray((int[]) {3, 5, 2, 4, 1, 1,
                                                          1, 5, 1, 1, 2, 7,
                                                          6, 1, 4, 4, 8, 3}, 3, 6);

    sortColsByMinElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);

}

static void test_getSquareOfMatrixIfSymmetric_symmetricMatrix() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 5,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {42, 42, 44,
                                                          42, 56, 50,
                                                          44, 50, 70}, 3, 3);

    getSquareOfMatrixIfSymmetric(&result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_getSquareOfMatrixIfSymmetric_nonSymmetricMatrix() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 4,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 4, 4,
                                                          4, 2, 6,
                                                          5, 6, 3}, 3, 3);

    getSquareOfMatrixIfSymmetric(&result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_transposeIfMatrixDoesntHaveEqualSumOfRows_uniqueSumsOfRowe() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 4,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 4, 5,
                                                          4, 2, 6,
                                                          4, 6, 3}, 3, 3);

    transposeIfMatrixDoesntHaveEqualSumOfRows(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_transposeIfMatrixDoesntHaveEqualSumOfRows_nonUniqueSumsOfRowe() {
    matrix result = createMatrixFromArray((int[]) {2, 4, 6,
                                                   5, 6, 3,
                                                   4, 2, 6}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {2, 4, 6,
                                                          5, 6, 3,
                                                          4, 2, 6}, 3, 3);

    transposeIfMatrixDoesntHaveEqualSumOfRows(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_areMutuallyInverseMatrices_mutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);

    assert(areMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_areMutuallyInverseMatrices_mutuallyNonInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 0,
                                               0, 1}, 2, 2);

    assert(!areMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_findSumOfMaxesOfPseudoDiagonal_commonCase1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}

static void test_findSumOfMaxesOfPseudoDiagonal_commonCase2() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3}, 2, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 16);

    freeMemMatrix(m);
}

static void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 1, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 11);

    freeMemMatrix(m);
}

static void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 4, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 11);

    freeMemMatrix(m);
}

static void test_getMinInArea_commonCase1() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

static void test_getMinInArea_commonCase2() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

static void test_getMinInArea_matrixOfUnitDimension() {
    matrix m = createMatrixFromArray((int[]) {10}, 1, 1);

    assert(getMinInArea(m) == 10);

    freeMemMatrix(m);
}

static void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray((int[]) {7, 12, 3, 4}, 1, 4);

    assert(getMinInArea(m) == 12);

    freeMemMatrix(m);
}

static void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray((int[]) {7, 12, 3, 4}, 4, 1);

    assert(getMinInArea(m) == 7);

    freeMemMatrix(m);
}

static void test_sortByDistances_equalDistances() {
    matrix result = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                                   1, 0, 2, 5,
                                                   4, 3, 1, 2}, 3, 4);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                                          1, 0, 2, 5,
                                                          4, 3, 1, 2}, 3, 4);

    sortByDistances(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortByDistances_commonCase() {
    matrix result = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                                   0, 0, 0, 1,
                                                   4, 3, 1, 3}, 3, 4);
    matrix assumedMatrix = createMatrixFromArray((int[]) {0, 0, 0, 1,
                                                          1, 2, 3, 4,
                                                          4, 3, 1, 3}, 3, 4);

    sortByDistances(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_countEqClassesByRowsSum_commonCase() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    int result = countEqClassesByRowsSum(m);
    int assumedResult = 3;

    assert(result == assumedResult);

    freeMemMatrix(m);
}

static void test_getNSpecialElement_commonCase() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);

    int result = getNSpecialElement(m);
    int assumedResult = 2;

    assert(result == assumedResult);

    freeMemMatrix(m);
}

static void test_replacePenultimateRow_commonCase() {
    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 1}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                          1, 4, 7,
                                                          7, 8, 1}, 3, 3);
    replacePenultimateRow(result);

    assert(areTwoMatricesEqual(result, assumedMatrix));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_countNonDecreasingRowsMatrices_commonCase() {
    matrix *am = createArrayOfMatricesFromArray((int[]) {7, 1,
                                                         1, 1,

                                                         1, 6,
                                                         2, 2,

                                                         5, 4,
                                                         2, 3,

                                                         1, 3,
                                                         7, 9}, 4, 2, 2);

    int result = countNonDecreasingRowsMatrices(am, 4);
    int assumedResult = 2;

    assert(result == assumedResult);

    freeMemMatrices(am, 4);
}

static void test_getNSpecialElement2_commonCase() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                              6, 2, 3, 8, 12,
                                              12, 12, 2, 1, 2}, 3, 5);

    int assumedResult = 4;
    int result = getNSpecialElement2(m);

    assert(assumedResult == result);

    freeMemMatrix(m);
}

static void test_getVectorIndexWithMaxAngle_commonCase() {
    matrix m = createMatrixFromArray((int[]) {4, 5, 6,
                                              7, 8, 9,
                                              1, 2, 3}, 3, 3);
    int v[3] = {2};

    int assumedResult = 2;
    int result = getVectorIndexWithMaxAngle(m, v);

    assert(assumedResult == result);

    freeMemMatrix(m);
}

static void test_getSpecialScalarProduct_commonCase() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 4,
                                              5, 6, 9,
                                              1, 3, 7}, 3, 3);

    long long assumedResult = 49;
    long long result = getSpecialScalarProduct(m);

    assert(assumedResult == result);

    freeMemMatrix(m);
}

void test_5d() {
    test_swapRowsWithMaxMinElements_maxMinSameRow();
    test_swapRowsWithMaxMinElements_commonCase();
    test_sortRowsByMaxElement_commonCase();
    test_sortRowsByMaxElement_theSameMax();
    test_sortColsByMinElement_commonCase();
    test_sortColsByMinElement_theSameMin();
    test_getSquareOfMatrixIfSymmetric_symmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_nonSymmetricMatrix();
    test_transposeIfMatrixDoesntHaveEqualSumOfRows_uniqueSumsOfRowe();
    test_transposeIfMatrixDoesntHaveEqualSumOfRows_nonUniqueSumsOfRowe();
    test_areMutuallyInverseMatrices_mutuallyInverseMatrices();
    test_areMutuallyInverseMatrices_mutuallyNonInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal_commonCase1();
    test_findSumOfMaxesOfPseudoDiagonal_commonCase2();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_getMinInArea_commonCase1();
    test_getMinInArea_commonCase2();
    test_getMinInArea_matrixOfUnitDimension();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();
    test_sortByDistances_equalDistances();
    test_sortByDistances_commonCase();
    test_countEqClassesByRowsSum_commonCase();
    test_getNSpecialElement_commonCase();
    test_replacePenultimateRow_commonCase();
    test_countNonDecreasingRowsMatrices_commonCase();
    test_getNSpecialElement2_commonCase();
    test_getVectorIndexWithMaxAngle_commonCase();
    test_getSpecialScalarProduct_commonCase();
}
