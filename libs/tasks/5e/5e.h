//
// Created by User on 02.03.2022.
//

#include "../../string/string_.h"

#ifndef LABS_LIBS_5E_H
#define LABS_LIBS_5E_H

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

void makeMixedStringFromTwo(char *s1, char *s2, char* sWrite);

#endif //LABS_LIBS_5E_H
