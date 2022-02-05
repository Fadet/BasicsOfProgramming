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

static size_t min2(const size_t x, const size_t y) {
    return x < y ? x : y;
}

vector createVector(const size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (NULL == data)
        raise_bad_allocation();

    return (vector) {(n == 0 ? NULL : data), 0, n};
}

void reserve(vector *v, const size_t newCapacity) {
    v->size = min2(v->size, v->capacity);
    v->capacity = newCapacity;

    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (NULL == v->data)
            raise_bad_allocation();
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(const vector *v) {
    return v->size == 0;
}

bool isFull(const vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(const vector *v, const size_t i) {
    return v->data[i];
}

void pushBack(vector *v, const int x) {
    if (isFull(v))
        reserve(v, isEmpty(v) ? 1 : v->capacity * 2);

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v))
        raise_empty_vector();

    v->size--;
}
