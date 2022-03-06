//
// Created by User on 02.03.2022.
//

#include "5e.h"
#include <ctype.h>
#include <memory.h>

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
