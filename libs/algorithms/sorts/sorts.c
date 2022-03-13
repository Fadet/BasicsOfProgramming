//
// Created by User on 13.03.2022.
//

#include "sorts.h"
#include "../algorithm.h"
#include <memory.h>
#include <stdbool.h>

#define SWAP(a, b) swap(a, b, sizeof(int))

void merge(const int *a, const size_t sizeA,
           const int *b, const size_t sizeB,
           int *c) {
    size_t indexA = 0;
    size_t indexB = 0;
    while (indexA < sizeA || indexB < sizeB)
        if (indexB == sizeB || indexA < sizeA && a[indexA] < b[indexB]) {
            c[indexA + indexB] = a[indexA];
            indexA++;
        } else {
            c[indexA + indexB] = b[indexB];
            indexB++;
        }
}

void _mergeSort(int *a, int left, int right, int *buf) {
    int size = right - left;
    if (size <= 1)
        return;

    int middle = left + (right - left) / 2;
    _mergeSort(a, left, middle, buf);
    _mergeSort(a, middle, right, buf);

    merge(a + left, middle - left,
          a + middle, right - middle,
          buf);
    memcpy(a + left, buf, size * sizeof(int));
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int *) malloc(sizeof(int) * n);
    _mergeSort(a, 0, n, buffer);
    free(buffer);
}

void selectionSort(int *a, const size_t n) {
    if (n <= 1)
        return;
    for (size_t i = 0; i < n; ++i) {
        size_t currentIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (a[j] < a[currentIndex])
                currentIndex = j;
        }
        SWAP(&a[i], &a[currentIndex]);
    }
}

void insertionSort(int *a, const size_t n) {
    for (int i = 1; i < n; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combSort(int *a, const size_t n) {
    double factor = 1.24733;
    size_t step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= factor;
        swapped = false;
        for (size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                SWAP(&a[i], &a[j]);
                swapped = true;
            }
        }
    }
}

void shellSort(int *a, size_t n) {
    for (int d = n / 2; d > 0; d /= 2)
        for (int i = d; i < n; ++i)
            for (int j = i - d; j >= 0 && a[j] > a[j + d]; j -= d)
                SWAP(&a[j], &a[j + d]);
}

static void getPrefixSums(int *a, size_t n) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < n; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

void LSD(int *a, size_t n) {
    int *buffer = (int *) calloc(n, sizeof(int));

    const int STEP = 8;
    const int MASK = 0b11111111;

    for (int byte = 0; byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < n; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                curByte = (a[i] >> (byte * STEP)) & MASK;

            values[curByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < n; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                curByte = (a[i] >> (byte * STEP)) & MASK;

            buffer[values[curByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * n);
    }

    free(buffer);
}

int cmp_int(const void *a, const void *b) {
    int arg1 = *(int *) a;
    int arg2 = *(int *) b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;

    return 0;
}

void stdlibQsort(int *a, size_t n) {
    qsort(a, n, sizeof(int), cmp_int);
}
