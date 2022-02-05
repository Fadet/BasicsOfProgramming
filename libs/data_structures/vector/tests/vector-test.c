//
// Created by User on 02.02.2022.
//

#include "vector-test.h"
#include "../vector.h"
#include <assert.h>

static void test_pushBack_emptyVector1() {
    vector v = createVector(0);

    pushBack(&v, 3);

    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVector(&v);
}

static void test_pushBack_emptyVector2() {
    vector v = createVector(5);

    pushBack(&v, 3);

    assert(v.size == 1);
    assert(v.capacity == 5);

    deleteVector(&v);
}

static void test_pushBack_fullVector() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 3};

    pushBack(&v, 10);

    assert(v.size == 4);
    assert(v.capacity == 6);

    deleteVector(&v);
}

static void test_pushBack_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    pushBack(&v, 10);

    assert(v.size == 4);
    assert(v.capacity == 9);

    deleteVector(&v);
}

static void test_popBack_notEmptyVector() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    popBack(&v);

    assert(v.size == 2);
    assert(v.capacity == 9);

    deleteVector(&v);
}

static void test_shrinkToFit_fullVector() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 3};

    shrinkToFit(&v);

    assert(v.size == 3);
    assert(v.capacity == 3);
}

static void test_shrinkToFit_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    shrinkToFit(&v);

    assert(v.size == 3);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_vector() {
    test_shrinkToFit_fullVector();
    test_shrinkToFit_averageCase();
    test_pushBack_emptyVector1();
    test_pushBack_emptyVector2();
    test_pushBack_fullVector();
    test_pushBack_averageCase();
    test_popBack_notEmptyVector();
}
