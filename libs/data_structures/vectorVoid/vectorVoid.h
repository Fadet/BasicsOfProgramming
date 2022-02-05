//
// Created by User on 05.02.2022.
//

#ifndef LABS_LIBS_VECTORVOID_H
#define LABS_LIBS_VECTORVOID_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vectorVoid{
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

// returns vector's descriptor of size n
// baseTypeSize represents a number of bytes which given type contains
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// changes the capacity of v to newCapacity
// reallocates the data of v (memory pointer is NULL if newCapacity equals 0)
void reserveV(vectorVoid *v, size_t newCapacity);

// sets size of v to zero
void clearV(vectorVoid *v);

// shrinks the capacity of v to its size
void shrinkToFitV(vectorVoid *v);

// frees the data of v
void deleteVectorV(vectorVoid *v);

#endif //LABS_LIBS_VECTORVOID_H
