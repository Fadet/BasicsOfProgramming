//
// Created by User on 13.03.2022.
//

#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "generating.h"

void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = INT_MIN / 2 + rand();
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwardsArray(int *a, size_t n) {
    int value = n - 1;
    for (int i = 0; i < n; i++)
        a[i] = value--;
}
