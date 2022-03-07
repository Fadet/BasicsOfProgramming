//
// Created by User on 02.03.2022.
//

#include "5e-test.h"
#include "../../../string/string_.h"
#include "../5e.h"
#include <stdio.h>
#include <assert.h>

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

static void test_replaceNumbersWithSpaces_commonCase() {
    char str[MAX_STRING_SIZE] = "A3B0C1";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "A   BC ";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceNumbersWithSpaces_emptyString() {
    char str[MAX_STRING_SIZE] = "";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceNumbersWithSpaces_onlyDigits() {
    char str[MAX_STRING_SIZE] = "123";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "      ";

    ASSERT_STRING(str, assumedStr);
}

static void test_replaceNumbersWithSpaces_onlyNonDigits() {
    char str[MAX_STRING_SIZE] = "abcd\n\tdslf";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "abcd\n\tdslf";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_commonCase() {
    char str[MAX_STRING_SIZE] = "dhfk aboba sjfsfm aboba";

    replaceWord(str, "aboba", "oleg");

    char assumedStr[] = "dhfk oleg sjfsfm oleg";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_emptyString() {
    char str[MAX_STRING_SIZE] = "";

    replaceWord(str, "aboba", "gg");

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_onlySpaces() {
    char str[MAX_STRING_SIZE] = "        ";

    replaceWord(str, "aboba", "gg");

    char assumedStr[] = "        ";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_noWordToReplace() {
    char str[MAX_STRING_SIZE] = "oleg oleg oleg oleg oleg";

    replaceWord(str, "aboba", "gg");

    char assumedStr[] = "oleg oleg oleg oleg oleg";

    ASSERT_STRING(assumedStr, str);

}

static void test_isLexicographicOrdered_allEqual() {
    char str[MAX_STRING_SIZE] = "oleg oleg oleg oleg oleg";

    assert(isLexicographicOrdered(str) == true);
}

static void test_isLexicographicOrdered_isOrdered() {
    char str[MAX_STRING_SIZE] = "oleg w x y z";

    assert(isLexicographicOrdered(str) == true);
}

static void test_isLexicographicOrdered_isNotOrdered() {
    char str[MAX_STRING_SIZE] = "oleg w x a z";

    assert(isLexicographicOrdered(str) == false);
}

static void test_countPalindromeWordsSeparatedWithComma_commonCase() {
    char str[] = "aboba,level,tenet,oleg,noon";

    int assumedResult = 4;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

static void test_countPalindromeWordsSeparatedWithComma_extraSpaces() {
    char str[] = "    aboba,level,tenet,oleg,noon     ";

    int assumedResult = 4;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

static void test_countPalindromeWordsSeparatedWithComma_emptyString() {
    char str[] = "";

    int assumedResult = 0;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

static void test_countPalindromeWordsSeparatedWithComma_zeroPalindromes() {
    char str[] = "oleg,ne_oleg,dead,inside";

    int assumedResult = 0;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

static void test_makeMixedStringFromTwo_commonCase() {
    char str1[] = "privet ti mimo";
    char str2[] = "no prohodish";
    char str[MAX_STRING_SIZE];

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "privet no ti prohodish mimo";

    ASSERT_STRING(assumedStr, str);
}

static void test_makeMixedStringFromTwo_emptyStrings() {
    char str1[] = "";
    char str2[] = "";
    char str[MAX_STRING_SIZE] = "sdrdrggdrgg";

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_makeMixedStringFromTwo_emptyString1() {
    char str1[] = "";
    char str2[] = "dtdgd dfgdg dgdfgd";
    char str[MAX_STRING_SIZE] = "";

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "dtdgd dfgdg dgdfgd";

    ASSERT_STRING(assumedStr, str);
}

static void test_makeMixedStringFromTwo_emptyString2() {
    char str1[] = "dtdgd dfgdg dgdfgd";
    char str2[] = "";
    char str[MAX_STRING_SIZE] = "";

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "dtdgd dfgdg dgdfgd";

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
    test_replaceNumbersWithSpaces_commonCase();
    test_replaceNumbersWithSpaces_emptyString();
    test_replaceNumbersWithSpaces_onlyDigits();
    test_replaceNumbersWithSpaces_onlyNonDigits();
    test_replaceWord_commonCase();
    test_replaceWord_emptyString();
    test_replaceWord_onlySpaces();
    test_replaceWord_noWordToReplace();
    test_isLexicographicOrdered_allEqual();
    test_isLexicographicOrdered_isOrdered();
    test_isLexicographicOrdered_isNotOrdered();
    test_countPalindromeWordsSeparatedWithComma_commonCase();
    test_countPalindromeWordsSeparatedWithComma_extraSpaces();
    test_countPalindromeWordsSeparatedWithComma_emptyString();
    test_countPalindromeWordsSeparatedWithComma_zeroPalindromes();
    test_makeMixedStringFromTwo_commonCase();
    test_makeMixedStringFromTwo_emptyStrings();
    test_makeMixedStringFromTwo_emptyString1();
    test_makeMixedStringFromTwo_emptyString2();
}
