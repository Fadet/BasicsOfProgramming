//
// Created by User on 02.03.2022.
//

#include "5e-test.h"
#include "../../../string/string_.h"
#include "../5e.h"
#include <stdio.h>

#define ASSERT_STRING(expected, got) assert_string(expected, got, \
                                __FILE__, __FUNCTION__, __LINE__)

static void assert_string(const char* expected, const char* got,
                          const char* file, const char* func,
                          const int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "Exception file: %s\n", file);
        fprintf(stderr, "Function: %s - line: %d\n", func, line);
        fprintf(stderr, "Got:      \"%s\"\n", got);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
    } else
        fprintf(stderr, "%s - OK!\n", func);
}

static void test_removeNonLetters_commonCase() {
    char str[] = "38r 3dbd f ";

    removeNonLetters(str);

    char res[] = "38r3dbdf";

    ASSERT_STRING(res, str);
}

static void test_removeNonLetters_zeroLetters() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

static void test_removeNonLetters_emptyString() {
    char str[] = "";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_5e() {
    test_removeNonLetters_commonCase();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_zeroLetters();
}
