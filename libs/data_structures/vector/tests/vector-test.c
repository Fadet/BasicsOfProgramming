//
// Created by User on 02.02.2022.
//

#include "vector-test.h"
#include "../vector.h"
#include <assert.h>

static void test_createVector_emptyVector() {
    vector v = createVector(0);

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(NULL == v.data);

    deleteVector(&v);
}

static void test_createVector_notEmptyVector() {
    vector v = createVector(10);

    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(NULL != v.data);

    deleteVector(&v);
}

static void test_reserve_makeEmptyVector() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    reserve(&v, 0);

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(NULL == v.data);

    deleteVector(&v);
}

static void test_reserve_shrinkVector() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vector v = (vector) {data, 5, 9};

    reserve(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 3);
    assert(NULL != v.data);

    deleteVector(&v);
}

static void test_reserve_extendVector() {
    int *data = (int *) malloc(sizeof(int) * 6);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vector v = (vector) {data, 5, 6};

    reserve(&v, 10);

    assert(v.size == 5);
    assert(v.capacity == 10);
    assert(NULL != v.data);

    deleteVector(&v);
}

static void test_clear_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 6);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vector v = (vector) {data, 5, 6};

    clear(&v);

    assert(v.size == 0);
    assert(v.capacity == 6);
    assert(NULL != v.data);

    deleteVector(&v);
}

static void test_isEmpty_emptyVector() {
    vector v = createVector(0);

    assert(isEmpty(&v));

    deleteVector(&v);
}

static void test_isEmpty_reservedVector() {
    vector v = createVector(5);

    assert(isEmpty(&v));

    deleteVector(&v);
}

static void test_isEmpty_notEmptyVector() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    assert(!isEmpty(&v));

    deleteVector(&v);
}

static void test_isFull_emptyVector() {
    vector v = createVector(0);

    assert(isFull(&v));

    deleteVector(&v);
}

static void test_isFull_fullVector() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 3};

    assert(isFull(&v));

    deleteVector(&v);
}

static void test_isFull_notFullVector() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 9};

    assert(!isFull(&v));

    deleteVector(&v);
}

static void test_getVectorValue_averageCase() {
    vector v = (vector) {(int[]) {1, 2, 3, 4}, 4, 4};

    assert(getVectorValue(&v, 1) == 2);
}

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

static void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]) {1, 2, 3, 4}, 4, 4};

    assert(*atVector(&v, 2) == 3);
}

static void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]) {1, 2, 3, 4}, 4, 4};

    assert(*atVector(&v, 3) == 4);
}

static void test_back_oneElementInVector() {
    vector v = (vector) {(int[]) {42}, 1, 1};

    assert(*back(&v) == 42);
}

static void test_back_averageCase() {
    vector v = (vector) {(int[]) {1337, 42, 1984}, 3, 3};

    assert(*back(&v) == 1984);
}

static void test_front_oneElementInVector() {
    vector v = (vector) {(int[]) {42}, 1, 1};

    assert(*front(&v) == 42);
}

static void test_front_averageCase() {
    vector v = (vector) {(int[]) {1337, 42, 1984}, 3, 3};

    assert(*front(&v) == 1337);
}

void test_vector() {
    test_clear_averageCase();
    test_createVector_emptyVector();
    test_createVector_notEmptyVector();
    test_reserve_makeEmptyVector();
    test_reserve_shrinkVector();
    test_reserve_extendVector();
    test_shrinkToFit_fullVector();
    test_shrinkToFit_averageCase();
    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
    test_isEmpty_reservedVector();
    test_isFull_emptyVector();
    test_isFull_fullVector();
    test_isFull_notFullVector();
    test_getVectorValue_averageCase();
    test_pushBack_emptyVector1();
    test_pushBack_emptyVector2();
    test_pushBack_fullVector();
    test_pushBack_averageCase();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_back_averageCase();
    test_front_oneElementInVector();
    test_front_averageCase();
}
