//
// Created by User on 02.02.2022.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

static void raise_bad_allocation() {
    fprintf(stderr, "bad allocation\n");
    exit(1);
}

static size_t min2(const size_t x, const size_t y) {
    return x < y ? x : y;
}

vector createVector(const size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (NULL == data)
        raise_bad_allocation();

    return (vector) {n == 0 ? NULL : data, 0, n};
}

void reserve(vector *v, const size_t newCapacity) {
    int *data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (NULL == data)
        raise_bad_allocation();

    v->data = newCapacity == 0 ? NULL : data;
    v->size = min2(v->size, v->capacity);
    v->capacity = newCapacity;
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