//
// Created by User on 02.02.2022.
//

#include "algorithm.h"

void swap(void *x, void *y, const size_t bytes) {
    char *px = x;
    char *py = y;
    for (size_t i = 0; i < bytes; i++) {
        char t = *px;
        *px = *py;
        *py = t;
        px++;
        py++;
    }
}
