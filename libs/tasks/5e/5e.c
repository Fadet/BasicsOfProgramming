//
// Created by User on 02.03.2022.
//

#include "5e.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>

static bool alwaysTrue(int ch) {
    return true;
}

static void reverseWord(WordDescriptor word) {
    char *endBuffer = copyIfReverse(word.end - 1,
                                    word.begin - 1,
                                    _stringBuffer,
                                    alwaysTrue);
    copy(_stringBuffer, endBuffer, word.begin);
}

static bool getWordCommaSeparated(char *source, WordDescriptor *word) {
    word->begin = findNonSpace(source);
    if (*word->begin == '\0')
        return false;

    word->end = find(word->begin, source + strlen(source), ',');
    if (*word->end == '\0')
        word->end = findSpace(word->begin);

    return true;
}

static bool isPalindrome(WordDescriptor word) {
    char *start = word.begin;
    char *end = word.end - 1;

    while (start < end) {
        if (*start != *end)
            return false;
        start++;
        end--;
    }

    return true;
}

void removeNonLetters(char *s) {
    char *endSrc = getEndOfString(s);
    char *dest = copyIf(s, endSrc, s, (bool (*)(int)) isgraph);
    *dest = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    if (!(*s))
        return;

    char *previous = s;
    while (*s) {
        if (*previous != *s)
            *(++previous) = *s;
        s++;
    }
    *(++previous) = '\0';
}

void removeExtraSpaces(char *s) {
    if (!(*s))
        return;

    char *writePos = s;
    s++;
    while (*s) {
        if (isspace(*writePos) && isspace(*s))
            *writePos = ' ';
        else
            *(++writePos) = *s;
        s++;
    }
    *(++writePos) = '\0';
}

void reverseWordsInString(char *s) {
    char *beginSearch = findNonSpace(s);
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseWord(word);
        beginSearch = word.end;
    }
}

void replaceNumbersWithSpaces(char *s) {
    char *endOfBuff = copy(s, s + strlen(s), _stringBuffer);
    char *start = _stringBuffer;

    memset(s, ' ', MAX_STRING_SIZE);

    while (start != endOfBuff) {
        if (!isdigit(*start))
            *s++ = *start;
        else
            s += *start - '0';
        start++;
    }

    *s = '\0';
}

void replaceWord(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    recPtr = source;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        char *endOfBuff = copy(source, getEndOfString(source), _stringBuffer);
        *endOfBuff = '\0';
        readPtr = _stringBuffer;
    }

    WordDescriptor currentWord;
    while (getWord(readPtr, &currentWord)) {
        if (wordcmp(word1, currentWord)) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else
            recPtr = copy(currentWord.begin, currentWord.end, recPtr);
        *recPtr++ = ' ';
        readPtr = currentWord.end;
    }

    if (recPtr != source)
        *--recPtr = '\0';
}

bool isLexicographicOrdered(char *s) {
    WordDescriptor previousWord;
    if (!getWord(s, &previousWord))
        return true;

    WordDescriptor currentWord;
    while (getWord(previousWord.end, &currentWord)) {
        if (!wordcmp(previousWord, currentWord) &&
            strcmp(previousWord.begin, currentWord.begin) > 0)
            return false;

        previousWord = currentWord;
    }

    return true;
}

void printWordsInReverseOrder(char *s) {
    getBagOfWords(&_bag1, s);

    WordDescriptor *end = _bag1.words;
    for (WordDescriptor *start = _bag1.words + _bag1.size - 1; start >= end; start--)
        printWord(*start);
}

void printWord(WordDescriptor word) {
    char *end = word.end;
    for (char *start = word.begin; start < end; ++start)
        printf("%c", *start);
    printf("\n");
}

int countPalindromeWordsSeparatedWithComma(char *s) {
    char *start = s;
    WordDescriptor currentWord;

    int counter = 0;
    while (getWordCommaSeparated(start, &currentWord)) {
        counter += isPalindrome(currentWord);
        start = currentWord.end + (*currentWord.end != '\0');
    }

    return counter;
}

void makeMixedStringFromTwo(char *s1, char *s2, char *sWrite) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *start = sWrite;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            start = copy(word1.begin, word1.end, start);
            *start++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            start = copy(word2.begin, word2.end, start);
            *start++ = ' ';
            beginSearch2 = word2.end;
        }
    }

    if (sWrite != start)
        start--;
    *start = '\0';
}

void reverseWordOrder(char *s) {
    char *endOfBuff = copy(s, s + strlen(s), _stringBuffer);
    *endOfBuff = '\0';

    WordDescriptor currentWord;
    char *start = s;
    while (getWordReverse(endOfBuff - 1, _stringBuffer - 1, &currentWord)) {
        start = copy(currentWord.begin, currentWord.end, start);
        *start++ = ' ';
        endOfBuff = currentWord.begin;
    }

    if (s != start)
        *--start = '\0';
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *word) {
    WordDescriptor previousWord;
    char *start = s;

    if (!getWord(start, &previousWord))
        return EMPTY_STRING;

    if (*find(previousWord.begin, previousWord.end, 'a') == 'a' ||
        *find(previousWord.begin, previousWord.end, 'A') == 'A')
        return FIRST_WORD_WITH_A;

    start = previousWord.end;
    WordDescriptor currentWord;
    while (getWord(start, &currentWord)) {
        if (*find(currentWord.begin, currentWord.end, 'a') == 'a' ||
            *find(currentWord.begin, currentWord.end, 'A') == 'A') {
            *word = previousWord;
            return WORD_FOUND;
        }
        start = currentWord.end;
        previousWord = currentWord;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

bool lastWordInFirstStringInSecondString(char *str1, char *str2, WordDescriptor *word) {
    if (!(*str1))
        return false;

    getBagOfWords(&_bag1, str2);

    WordDescriptor currentWord;
    char *end = getEndOfString(str1);
    while (getWordReverse(end - 1, str1 - 1, &currentWord)) {
        if (findWordInBag(&_bag1, currentWord) != -1) {
            *word = currentWord;
            return true;
        }

        end = currentWord.begin;
    }

    return false;
}