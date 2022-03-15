//
// Created by User on 13.03.2022.
//

#ifndef LABS_LIBS_SORTS_H
#define LABS_LIBS_SORTS_H

#include <stdlib.h>

void mergeSort(int *a, size_t n);

long long getMergeSortComps(int *a, size_t n);

void selectionSort(int *a, size_t n);

long long getSelectionSortComps(int *a, size_t n);

void insertionSort(int *a, size_t n);

long long getInsertionSortComps(int *a, size_t n);

void combSort(int *a, size_t n);

long long getCombSortComps(int *a, size_t n);

void shellSort(int *a, size_t n);

long long getShellSortComps(int *a, size_t n);

void LSD_sort(int *a, size_t n);

long long getLSD_sortComps(int *a, size_t n);

void stdlibQsort(int *a, size_t n);

#endif //LABS_LIBS_SORTS_H
