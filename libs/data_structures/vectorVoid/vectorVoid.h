//
// Created by User on 05.02.2022.
//

#ifndef LABS_LIBS_VECTORVOID_H
#define LABS_LIBS_VECTORVOID_H

#include <stdlib.h>

typedef struct vectorVoid{
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

#endif //LABS_LIBS_VECTORVOID_H
