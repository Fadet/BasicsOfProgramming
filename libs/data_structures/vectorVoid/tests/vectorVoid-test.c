//
// Created by User on 05.02.2022.
//

//
// Created by User on 02.02.2022.
//

#include "vectorVoid-test.h"
#include "../vectorVoid.h"
#include <assert.h>

static void test_createVectorV_emptyVectorVoid() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(NULL == v.data);

    deleteVectorV(&v);
}

static void test_createVectorV_notEmptyVectorVoid() {
    vectorVoid v = createVectorV(10, sizeof(int));

    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(NULL != v.data);

    deleteVectorV(&v);
}

static void test_reserveV_makeEmptyVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    reserveV(&v, 0);

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(NULL == v.data);

    deleteVectorV(&v);
}

static void test_reserveV_shrinkVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 5, 9, sizeof(int)};

    reserveV(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 3);
    assert(NULL != v.data);

    deleteVectorV(&v);
}

static void test_reserveV_extendVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 6);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 5, 6, sizeof(int)};

    reserveV(&v, 10);

    assert(v.size == 5);
    assert(v.capacity == 10);
    assert(NULL != v.data);

    deleteVectorV(&v);
}

static void test_clearV_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 6);
    for (int i = 0; i < 5; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 5, 6, sizeof(int)};

    clearV(&v);

    assert(v.size == 0);
    assert(v.capacity == 6);
    assert(NULL != v.data);

    deleteVectorV(&v);
}

static void test_isEmptyV_emptyVectorVoid() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isEmptyV(&v));

    deleteVectorV(&v);
}

static void test_isEmptyV_reserveVdVectorVoid() {
    vectorVoid v = createVectorV(5, sizeof(int));

    assert(isEmptyV(&v));

    deleteVectorV(&v);
}

static void test_isEmptyV_notEmptyVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    assert(!isEmptyV(&v));

    deleteVectorV(&v);
}

static void test_isFullV_emptyVectorVoid() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isFullV(&v));

    deleteVectorV(&v);
}

static void test_isFullV_fullVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 3, sizeof(int)};

    assert(isFullV(&v));

    deleteVectorV(&v);
}

static void test_isFullV_notFullVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    assert(!isFullV(&v));

    deleteVectorV(&v);
}

static void test_getVectorValueV_averageCase() {
    vectorVoid v = (vectorVoid) {(int[]) {1, 2, 3, 4}, 4, 4, sizeof(int)};

    int x;
    getVectorValueV(&v, 1, &x);

    assert(x == 2);
}

static void test_setVectorValueV_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    int source = 5;
    setVectorValueV(&v, 1, &source);

    int destination;
    getVectorValueV(&v, 1, &destination);

    assert(destination == source);

    deleteVectorV(&v);
}

static void test_pushBackV_emptyVectorVoid1() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 3;
    pushBackV(&v, &x);

    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}

static void test_pushBackV_emptyVectorVoid2() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int x = 3;
    pushBackV(&v, &x);

    assert(v.size == 1);
    assert(v.capacity == 5);

    deleteVectorV(&v);
}

static void test_pushBackV_fullVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 3, sizeof(int)};

    int x = 10;
    pushBackV(&v, &x);

    assert(v.size == 4);
    assert(v.capacity == 6);

    deleteVectorV(&v);
}

static void test_pushBackV_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    int x = 10;
    pushBackV(&v, &x);

    assert(v.size == 4);
    assert(v.capacity == 9);

    deleteVectorV(&v);
}

static void test_popBackV_notEmptyVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    popBackV(&v);

    assert(v.size == 2);
    assert(v.capacity == 9);

    deleteVectorV(&v);
}

static void test_shrinkToFitV_fullVectorVoid() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 3, sizeof(int)};

    shrinkToFitV(&v);

    assert(v.size == 3);
    assert(v.capacity == 3);
}

static void test_shrinkToFitV_averageCase() {
    int *data = (int *) malloc(sizeof(int) * 9);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 9, sizeof(int)};

    shrinkToFitV(&v);

    assert(v.size == 3);
    assert(v.capacity == 3);

    deleteVectorV(&v);
}

static void test_atVectorV_notEmptyVector() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vectorVoid v = (vectorVoid) {data, 3, 3, sizeof(int)};

    assert(*(int *) atVectorV(&v, 2) == 2);
}

static void test_atVectorV_requestToLastElement() {
    vectorVoid v = (vectorVoid) {(int[]) {1, 2, 3, 4}, 4, 4, sizeof(int)};

    assert(*(int *) atVectorV(&v, 3) == 4);
}

static void test_backV_oneElementInVector() {
    vectorVoid v = (vectorVoid) {(int[]) {42}, 1, 1, sizeof(int)};

    assert(*(int *) backV(&v) == 42);
}

static void test_backV_averageCase() {
    vectorVoid v = (vectorVoid) {(int[]) {1337, 42, 1984}, 3, 3, sizeof(int)};

    assert(*(int *) backV(&v) == 1984);
}

static void test_frontV_oneElementInVector() {
    vectorVoid v = (vectorVoid) {(int[]) {42}, 1, 1, sizeof(int)};

    assert(*(int *) frontV(&v) == 42);
}

static void test_frontV_averageCase() {
    vectorVoid v = (vectorVoid) {(int[]) {1337, 42, 1984}, 3, 3, sizeof(int)};

    assert(*(int *) frontV(&v) == 1337);
}

void test_vectorVoid() {
    test_clearV_averageCase();
    test_createVectorV_emptyVectorVoid();
    test_createVectorV_notEmptyVectorVoid();
    test_reserveV_makeEmptyVectorVoid();
    test_reserveV_shrinkVectorVoid();
    test_reserveV_extendVectorVoid();
    test_shrinkToFitV_fullVectorVoid();
    test_shrinkToFitV_averageCase();
    test_isEmptyV_emptyVectorVoid();
    test_isEmptyV_notEmptyVectorVoid();
    test_isEmptyV_reserveVdVectorVoid();
    test_isFullV_emptyVectorVoid();
    test_isFullV_fullVectorVoid();
    test_isFullV_notFullVectorVoid();
    test_getVectorValueV_averageCase();
    test_setVectorValueV_averageCase();
    test_pushBackV_emptyVectorVoid1();
    test_pushBackV_emptyVectorVoid2();
    test_pushBackV_fullVectorVoid();
    test_pushBackV_averageCase();
    test_popBackV_notEmptyVectorVoid();
    test_atVectorV_notEmptyVector();
    test_atVectorV_requestToLastElement();
    test_backV_averageCase();
    test_backV_oneElementInVector();
    test_frontV_averageCase();
    test_frontV_oneElementInVector();
}
