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

static void test_removeAdjacentEqualLetters_emptyString() {
    char str[] = "";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_unitOccurrences() {
    char str[] = "abcdefhj123";

    removeAdjacentEqualLetters(str);

    char assumedStr[] = "abcdefhj123";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_commonCase() {
    char str[] = "aaaabbbcccd34da23ass";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "abcd34da23as";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_oneLetter() {
    char str[] = "aaaaaaaaaaaaaaaa";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "a";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_emptyString() {
    char str[] = "";

    removeExtraSpaces(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_noSpaces() {
    char str[] = "rdhhthhhs";

    removeExtraSpaces(str);

    char assumedStr[] = "rdhhthhhs";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_commonCase() {
    char str[] = "a\t\t  aboba f\txxx  dg";

    removeExtraSpaces(str);

    char assumedStr[] = "a aboba f\txxx dg";

    ASSERT_STRING(assumedStr, str);
}

static void test_reverseWord_commonCase() {
    char str[] = "oleg 123";

    reverseWordsInString(str);

    char assumedStr[] = "gelo 321";

    ASSERT_STRING(assumedStr, str);

}

static void test_reverseWord_emptyString() {
    char str[] = "";

    reverseWordsInString(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);

}

void test_5e() {
    test_removeNonLetters_commonCase();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_zeroLetters();
    test_removeAdjacentEqualLetters_commonCase();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_unitOccurrences();
    test_removeAdjacentEqualLetters_oneLetter();
    test_removeExtraSpaces_commonCase();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_noSpaces();
    test_reverseWord_commonCase();
    test_reverseWord_emptyString();
}
