//
// Created by User on 13.03.2022.
//

#include "../../generating/generating.h"
#include "../sorts.h"
#include "../../array/array.h"
#include "sorts-test.h"

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName,
               FILE *log_file) {

    static size_t runCounter = 1;

    int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    fprintf(log_file, " Run #%zu| ", runCounter++);
    fprintf(log_file, " Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time);

    fprintf(log_file, "Status: ");
    if (isOrdered(innerBuffer, size)) {
        fprintf(log_file, "OK! Time: %.3f\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (NULL == f) {
            fprintf(log_file, "FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        fprintf(log_file, "Wrong!\n");

        outputArray(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    SortFunc sorts[] = {
            {mergeSort,     "mergeSort"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {combSort,      "combSort"},
            {shellSort,     "shellSort"},
            {LSD_sort,      "LSD_sort"},
            {stdlibQsort,   "stdQSort"},
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generating[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"},
    };

    const unsigned CASES_N = ARRAY_SIZE(generating);

    char log_filename[128] = "./logs/time.log";
    FILE *log_file = fopen(log_filename, "a");
    if (NULL == log_file) {
        printf("FileOpenError %s", log_filename);
        exit(1);
    }

    for (size_t size = 10000; size <= 100000; size += 10000) {
        fprintf(log_file, "----------------------------\n");
        fprintf(log_file, "Size: %d\n", size);

        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generating[j].name);
                checkTime(sorts[i].sort,
                          generating[j].generate,
                          size,
                          filename, log_file);

            }
        }

        fprintf(log_file, "\n");
    }

    fclose(log_file);
}

void checkCompares(long long int (*sortFunc)(int *, size_t),
                   void (*generateFunc)(int *, size_t),
                   size_t size, char *experimentName,
                   FILE *log_file) {
    static size_t runCounter = 1;

    int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    fprintf(log_file, " Run #%zu| ", runCounter++);
    fprintf(log_file, " Name: %s\n", experimentName);

    long long nComps = sortFunc(innerBuffer, size);

    fprintf(log_file, "Status: ");
    if (isOrdered(innerBuffer, size)) {
        fprintf(log_file, "OK! Compares: %lld\n", nComps);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (NULL == f) {
            fprintf(log_file, "FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        fprintf(log_file, "Wrong!\n");

        outputArray(innerBuffer, size);

        exit(1);
    }
}

void comparesExperiment() {
    SortFuncCompares sorts[] = {
            {getMergeSortComps,     "mergeSort"},
            {getSelectionSortComps, "selectionSort"},
            {getInsertionSortComps, "insertionSort"},
            {getCombSortComps,      "combSort"},
            {getShellSortComps,     "shellSort"},
            {getLSD_sortComps,      "LSD_sort"},
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generating[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"},
    };

    const unsigned CASES_N = ARRAY_SIZE(generating);

    char log_filename[128] = "./logs/compares.log";
    FILE *log_file = fopen(log_filename, "a");
    if (NULL == log_file) {
        printf("FileOpenError %s", log_filename);
        exit(1);
    }

    for (size_t size = 10000; size <= 100000; size += 10000) {
        fprintf(log_file, "----------------------------\n");
        fprintf(log_file, "Size: %d\n", size);

        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_compares",
                        sorts[i].name, generating[j].name);
                checkCompares(sorts[i].sort,
                          generating[j].generate,
                          size,
                          filename, log_file);

            }
        }

        fprintf(log_file, "\n");
    }

    fclose(log_file);
}
