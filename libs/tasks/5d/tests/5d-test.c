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
}
