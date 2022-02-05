//
// Created by User on 02.02.2022.
//

#ifndef LABS_LIBS_VECTOR_H
#define LABS_LIBS_VECTOR_H

#include <stdlib.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// returns vector's descriptor of size n
vector createVector(size_t n);

// changes the capacity of v to newCapacity
// reallocates the memory of v (memory pointer is NULL, if newCapacity equals 0)
void reserve(vector *v, size_t newCapacity);

// sets size of v to zero
void clear(vector *v);

// shrinks the capacity of v to its size
void shrinkToFit(vector *v);

// frees the memory of v
void deleteVector(vector *v);

#endif //LABS_LIBS_VECTOR_H
