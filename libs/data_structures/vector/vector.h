//
// Created by User on 02.02.2022.
//

#ifndef LABS_LIBS_VECTOR_H
#define LABS_LIBS_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// returns vector's descriptor of size n
vector createVector(size_t n);

// changes the capacity of v to newCapacity
// reallocates the data of v (memory pointer is NULL if newCapacity equals 0)
void reserve(vector *v, size_t newCapacity);

// sets size of v to zero
void clear(vector *v);

// shrinks the capacity of v to its size
void shrinkToFit(vector *v);

// sets v to the empty vector
void deleteVector(vector *v);

// returns true if size of v is zero else returns false
bool isEmpty(const vector *v);

// returns true if size of v equals its capacity else returns false
bool isFull(const vector *v);

// returns i-th value of v
int getVectorValue(const vector *v, size_t i);

// adds x to the end of v
// extends space twice if v is full
void pushBack(vector *v, int x);

// deletes the last element of v
void popBack(vector *v);

// returns a pointer of index element of v
// raises an error if index is invalid
int *atVector(const vector *v, size_t index);

// returns a pointer of the last element of v
int *back(const vector *v);

// returns a pointer of the first element of v
int *front(const vector *v);

#endif //LABS_LIBS_VECTOR_H
