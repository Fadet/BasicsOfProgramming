#ifndef LABS_LIBS_ALGORITHM_H
#define LABS_LIBS_ALGORITHM_H

#include <stdlib.h>

//possible types of a sequence
enum SequenceType{
    EQUAL,
    NON_DECREASING,
    NON_INCREASING,
    DISORDERED,
    EMPTY,
    UNITARY
};

// inputs values to array a of size n
void inputArray(int *a, const size_t n);

// prints array a of size n
void outputArray(const int *a, const size_t n);

// returns an index of the first found x in array a of size n
// returns -1 if x is not found
int find(const int *a, const size_t n, const int x);

// returns an index of the first negative number in array a of size n
// returns -1 if such number is not found
int getFirstNegativeIndex(const int *a, const size_t n);

// returns an index of the first number which is true for predicate f in array a of size n
// returns -1 if such number is not found
int findIf(const int *a, const size_t n, int (*f)(int));

// returns an index of the last even number in array a of size n
// returns -1 if such number is not found
int getLastEvenIndex(const int *a, const size_t n);

// returns an index of the last number which is true for predicate f in array a of size n
// returns -1 if such number is not found
int rfindIf(const int *a, const size_t n, int (*f)(int));

// returns an amount of negative numbers in array a of size n
int countNegative(const int *a, const size_t n);

// returns an amount of numbers which are true for predicate f in array a of size n
int countIf(const int *a, const size_t n, int (*f)(int));

// swaps x and y by their values
void swapInt(int *x, int *y);

// reverses array a of size n
void reverseArray(int *a, const size_t n);

// returns 1 if array a of size n is a palindrome
// else returns 0
int isPalindrome(const int *a, const size_t n);

// sorts array a of size n by predicate f
void selectionSort(int *a, const size_t n, int (*f)(int, int));

// deletes odd numbers in array a of size n
void deleteOdd(int *a, int *n);

// inserts value to array a of size n by index pos
void insertValue(int *a, size_t *n, const size_t pos, const int value);

// inserts value to the end of array a of size n
void append(int *a, size_t *n, int value);

// deletes an element in array a of size a by index pos
// order remains unchanged
void deleteByPos(int *a, size_t *n, const size_t pos);

// deletes an element in array a of size a by index pos
// order changes
void deleteByPosDisordered(int *a, size_t *n, const size_t pos);

// cyclically shifts elements of array a of size n to the left
void cyclicLeftShift(int *a, const size_t n, size_t offset);

// applies f function to each element of array a of given size
void forEach(int *a, const size_t size, void (*f)(int *));

// returns 1 if at least one element of array a of given size
// is true for predicate f else returns 0
int any(const int *a, const size_t size, int (*f)(int));

// returns 1 if all elements of array a of given size
// is true for predicate f else returns 0
int all(const int *a, const size_t size, int (*f)(int));

// splits array a of size sizeA by predicate f
// true elements are writen to array b of size *sizeB
// false elements are writen to array c of size *sizeC
void arraySplit(const int *a, const size_t sizeA,
                int *b, size_t *sizeB,
                int *c, size_t *sizeC,
                int (*f)(int));

// returns type of sequence in array a of size n
int getSequenceType(const int *a, const size_t n);

// returns a sum of array a of size n
int arraySum(const int *a, int n);

#endif //LABS_LIBS_ALGORITHM_H