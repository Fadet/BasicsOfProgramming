//
// Created by user on 28.02.2022.
//

#ifndef LABS_LIBS_STRING__H
#define LABS_LIBS_STRING__H

#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 10125
#define MAX_N_WORDS_IN_STRING 125
#define MAX_WORD_SIZE 80

static char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static BagOfWords _bag1;
static BagOfWords _bag2;

// returns a size of string begin
size_t strlen(const char *begin);

// returns a pointer to a value ch on interval [begin, end)
// if is not found returns end
char *find(char *begin, char *end, int ch);

// returns a pointer to the first non-space symbol in string begin
// if is not found returns a pointer to the first null-symbol in string
char *findNonSpace(char *begin);

// returns a pointer to the first space symbol in string begin
// if is not found returns a pointer to the first null-symbol in string
char *findSpace(char *begin);

/// \param rbegin a pointer to the last non-null symbol in string
/// \param rend a pointer to the first symbol in string
/// \return a pointer to the first non-space symbol from the right
/// returns rend if is not found
char *findNonSpaceReverse(char *rbegin, char *rend);

/// \param rbegin a pointer to the last non-null symbol in string
/// \param rend a pointer to the first symbol in string
/// \return a pointer to the first space symbol from the right
/// returns rend if is not found
char *findSpaceReverse(char *rbegin, char *rend);

// returns a negative value if lhs lies before rhs in lexicographic case
// returns 0 if they are equal
// else returns a positive value
int strcmp(const char *lhs, const char *rhs);

// writes a memory fragment from beginSource to endSource
// by address beginDestination
// returns a pointer to the first free-to-write element in destination
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

// writes elements from beginSource to endSource
// by address beginDestination if predicate f is true
// returns a pointer to the first free-to-write element in destination
char *copyIf(const char *beginSource, const char *endSource,
             char *beginDestination, bool (*f)(int));

// writes elements from rbeginSource to rendSource from the right
// by address beginDestination if predicate f is true
// returns a pointer to the first free-to-write element in destination
char *copyIfReverse(const char *rbeginSource, const char *rendSource,
                    char *beginDestination, bool (*f)(int));

// returns a pointer to the end of string str
char *getEndOfString(char *str);

bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

bool wordcmp(WordDescriptor w1, WordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

#endif //LABS_LIBS_STRING__H
