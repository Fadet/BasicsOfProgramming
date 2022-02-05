//
// Created by User on 05.02.2022.
//

#include "vectorVoid.h"
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

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize) {
    void *data = malloc(baseTypeSize * n);
    if (NULL == data)
        raise_bad_allocation();

    return (vectorVoid) {(n == 0 ? NULL : data), 0, n};
}

void reserveV(vectorVoid * const v, const size_t newCapacity) {
    v->capacity = newCapacity;
    v->size = min2(v->size, v->capacity);
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    if (NULL == v->data && newCapacity != 0)
        raise_bad_allocation();
}

void clearV(vectorVoid * const v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid * const v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid * const v) {
    reserveV(v, 0);
}