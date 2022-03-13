#include "array.h"
#include <math.h>
#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int arrayFind(const int *a, const size_t n, const int x) {
    int i = 0;
    while (i < n && a[i] != x)
        i++;

    return i < n ? i : -1;
}

int getFirstNegativeIndex(const int *a, const size_t n) {
    int i = 0;
    while (i < n && a[i] >= 0)
        i++;

    return i < n ? i : -1;
}

int findIf(const int *a, const size_t n, int (*f)(int)) {
    int i = 0;
    while (i < n && !f(a[i]))
        i++;

    return i < n ? i : -1;
}

int getLastEvenIndex(const int *a, const size_t n) {
    int i = n - 1;
    while (i >= 0 && a[i] % 2)
        i--;

    return i >= 0 ? i : -1;
}

int rfindIf(const int *a, const size_t n, int (*f)(int)) {
    int i = n - 1;
    while (i >= 0 && !f(a[i]))
        i--;

    return i >= 0 ? i : -1;
}

int countNegative(const int *a, const size_t n) {
    int counter = 0;
    for (size_t i = 0; i < n; ++i)
        if (a[i] < 0)
            counter++;

    return counter;
}

int countIf(const int *a, const size_t n, int (*f)(int)) {
    int counter = 0;
    for (size_t i = 0; i < n; ++i)
        if (f(a[i]))
            counter++;

    return counter;
}

void swapInt(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void reverseArray(int *a, const size_t n) {
    for (size_t i = 0, j = n - 1; i < j; i++, j--)
        swapInt(&a[i], &a[j]);
}

int isPalindrome(const int *a, const size_t n) {
    for (size_t i = 0, j = n - 1; i < j; i++, j--)
        if (a[i] != a[j])
            return 0;
    return 1;
}

void selectionSort_(int *a, const size_t n, int (*f)(int, int)) {
    if (n <= 1)
        return;
    for (size_t i = 0; i < n; ++i) {
        size_t currentIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (f(a[j], a[currentIndex]))
                currentIndex = j;
        }
        swapInt(&a[i], &a[currentIndex]);
    }
}

void deleteOdd(int *a, int *n) {
    int iRead = 0;
    while (iRead < *n && a[iRead] % 2 == 0)
        iRead++;
    int iWrite = iRead;
    while (iRead < *n) {
        if (a[iRead] % 2 == 0) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void insertValue(int *a, size_t *n, const size_t pos, const int value) {
    for (size_t i = *n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = value;
    ++*n;
}

void append(int *a, size_t *n, int value) {
    a[*n] = value;
    ++*n;
}

void deleteByPos(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i - 1] = a[i];
    (*n)--;
}

void deleteByPosDisordered(int *a, size_t *n, const size_t pos) {
    swapInt(&a[pos], &a[--*n]);
}

void cyclicLeftShift(int *a, const size_t n, size_t offset) {
    offset %= n;
    int b[offset];
    for (size_t i = 0; i < offset; i++)
        b[i] = a[i];
    for (size_t i = offset; i < n; i++)
        a[i - offset] = a[i];
    for (size_t i = n - offset, j = 0; i < n; i++, j++)
        a[i] = b[j];
}

// applies f function to each element of array a of given size
void forEach(int *a, const size_t size, void (*f)(int *)) {
    for (int i = 0; i < size; ++i)
        f(&a[i]);
}

int any(const int *a, const size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++)
        if (f(a[i]))
            return 1;
    return 0;
}

int all(const int *a, const size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++)
        if (!f(a[i]))
            return 0;
    return 1;
}

void arraySplit(const int *a, const size_t sizeA,
                int *b, size_t *sizeB,
                int *c, size_t *sizeC,
                int (*f)(int)) {
    for (size_t i = 0; i < sizeA; i++)
        if (f(a[i]))
            append(b, sizeB, a[i]);
        else
            append(c, sizeC, a[i]);
}

int getSequenceType(const int *a, const size_t n) {
    if (n == 0)
        return EMPTY;
    else if (n == 1)
        return UNITARY;

    int isEqual = 1;
    int isNonDecreasing = 1;
    int isNonIncreasing = 1;
    for (size_t i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && isEqual) {
            isEqual = 0;
            isNonDecreasing = 1;
            isNonIncreasing = 1;
        }
        if (a[i] > a[i - 1] || a[i] == a[i - 1] && isNonDecreasing)
            isNonIncreasing = 0;
        if (a[i] < a[i - 1] || a[i] == a[i - 1] && isNonIncreasing)
            isNonDecreasing = 0;
    }

    if (isEqual)
        return EQUAL;
    else if (isNonDecreasing)
        return NON_DECREASING;
    else if (isNonIncreasing)
        return NON_INCREASING;
    else
        return DISORDERED;
}

int arraySum(const int *a, const int n) {
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

bool isOrdered(const int *a, const size_t n) {
    for (size_t i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

