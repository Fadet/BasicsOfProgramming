//
// Created by user on 28.02.2022.
//

#include "string_.h"
#include <ctype.h>
#include <memory.h>


size_t strlen(const char *begin) {
    const char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }

    return begin;
}

char *findNonSpaceReverse(char *rbegin, char *rend) {
    while (rbegin != rend && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char *findSpaceReverse(char *rbegin, char *rend) {
    while (rbegin != rend && !isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0') {
        lhs++, rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

char *copyIf(const char *beginSource, const char *endSource,
             char *beginDestination, bool (*f)(int)) {
    for (const char *begin = beginSource; begin < endSource; ++begin)
        if (f(*begin))
            *beginDestination++ = *begin;

    return beginDestination;
}

char *copyIfReverse(const char *rbeginSource, const char *rendSource,
                    char *beginDestination, bool (*f)(int)) {
    for (const char *begin = rbeginSource; begin > rendSource; --begin)
        if (f(*begin))
            *beginDestination++ = *begin;

    return beginDestination;
}

char *getEndOfString(char *str) {
    while (*str)
        str++;

    return str;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);
    return true;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (*word->begin == '\0')
        return false;

    word->end = findSpaceReverse(rbegin, rend);
    word->begin++;
    word->end++;
    return true;
}

bool wordcmp(WordDescriptor w1, WordDescriptor w2) {
    char *start1 = w1.begin;
    char *start2 = w2.begin;
    unsigned long size = w1.end - start1;
    if (size != w2.end - start2)
        return false;

    return memcmp(start1, start2, size) == 0;
}
