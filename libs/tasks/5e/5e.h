//
// Created by User on 02.03.2022.
//

#include "../../string/string_.h"

#ifndef LABS_LIBS_5E_H
#define LABS_LIBS_5E_H

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

typedef enum WordBeforeFirstSameWordInOtherStringReturnCode {
    EMPTY_STRING2,
    WORD_FOUND2,
    SINGLE_WORD,
    NOT_FOUND_REQUIRED_WORD
} WordBeforeFirstSameWordInOtherStringReturnCode;

void removeNonLetters(char *s);

void removeAdjacentEqualLetters(char *s);

void removeExtraSpaces(char *s);

void reverseWordsInString(char *s);

void replaceNumbersWithSpaces(char *s);

void replaceWord(char *source, char *w1, char *w2);

bool isLexicographicOrdered(char *s);

void printWordsInReverseOrder(char *s);

void printWord(WordDescriptor word);

int countPalindromeWordsSeparatedWithComma(char *s);

void makeMixedStringFromTwo(char *s1, char *s2, char *sWrite);

void reverseWordOrder(char *s);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *word);

bool lastWordInFirstStringInSecondString(char *str1, char *str2, WordDescriptor *word);

bool hasEqualWords(char *s);

bool hasWordsCreatedWithTheSameLetters(char *s);

void getStringOfWordsThatDoNotEqualToTheLast(char *source, char *dist);

WordBeforeFirstSameWordInOtherStringReturnCode getWordBeforeFirstSameWordInOtherString(char *s1, char *s2, WordDescriptor *word);

void deleteWordsThatEqualToTheLast(char *s);

void complementStringThatContainsLessWords(char *s1, char *s2);

bool areAllWordLettersInString(char *s, WordDescriptor word);

#endif //LABS_LIBS_5E_H
