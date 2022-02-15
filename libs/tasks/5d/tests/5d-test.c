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

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

void test_5d() {
    test_swapRowsWithMaxMinElements_maxMinSameRow();
    test_swapRowsWithMaxMinElements_commonCase();
    test_sortRowsByMaxElement_commonCase();
    test_sortRowsByMaxElement_theSameMax();
}
