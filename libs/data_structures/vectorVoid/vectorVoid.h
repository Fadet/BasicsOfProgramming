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

// sets v to the empty vector
void deleteVectorV(vectorVoid *v);

// returns true if size of v is zero else returns false
bool isEmptyV(const vectorVoid *v);

// returns true if size of v equals its capacity else returns false
bool isFullV(const vectorVoid *v);

// writes by address of destination the i-th value of v
void getVectorValueV(const vectorVoid *v, size_t i, void *destination);

// writes from address of source the i-th value of v
void setVectorValueV(vectorVoid *v, size_t i, const void *source);

// adds value from the source to the end of v
// extends space twice if v is full
void pushBackV(vectorVoid *v, const void *source);

// deletes the last element of v
void popBackV(vectorVoid *v);

#endif //LABS_LIBS_VECTORVOID_H
