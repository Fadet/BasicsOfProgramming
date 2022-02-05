//
// Created by User on 02.02.2022.
//

#include "vector.h"
#include <stdio.h>

static void raise_bad_allocation() {
    fprintf(stderr, "bad allocation\n");
    exit(1);
}

static void raise_empty_vector() {
    fprintf(stderr, "vector is empty\n");
    exit(1);
}

static void raise_index_error(const size_t index) {
    fprintf(stderr, "IndexError: a[%llu] doesn't exist\n", index);
    exit(1);
}

static size_t min2(const size_t x, const size_t y) {
    return x < y ? x : y;
}

vector createVector(const size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (NULL == data)
        raise_bad_allocation();

    return (vector) {(n == 0 ? NULL : data), 0, n};
}

void reserve(vector *const v, const size_t newCapacity) {
    v->capacity = newCapacity;
    v->size = min2(v->size, v->capacity);
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (NULL == v->data && newCapacity != 0)
        raise_bad_allocation();
}

void clear(vector *const v) {
    v->size = 0;
}

void shrinkToFit(vector *const v) {
    reserve(v, v->size);
}

void deleteVector(vector *const v) {
    reserve(v, 0);
}

bool isEmpty(const vector *const v) {
    return v->size == 0;
}

bool isFull(const vector *const v) {
    return v->size == v->capacity;
}

int getVectorValue(const vector *const v, const size_t i) {
    return v->data[i];
}

void pushBack(vector *const v, const int x) {
    if (isFull(v))
        reserve(v, isEmpty(v) ? 1 : v->capacity * 2);

    v->data[v->size++] = x;
}

void popBack(vector *const v) {
    if (isEmpty(v))
        raise_empty_vector();

    v->size--;
}

int *atVector(const vector *const v, const size_t index) {
    if (index >= v->size)
        raise_index_error(index);

    return v->data + index;
}

int *back(const vector *const v) {
    return v->data + v->size - 1;
}

int *front(const vector *const v) {
    return v->data;
}
