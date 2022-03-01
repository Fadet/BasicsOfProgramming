//
// Created by User on 02.03.2022.
//

#include "5e.h"
#include "../../string/string_.h"
#include <ctype.h>

void removeNonLetters(char *s) {
    char *endSrc = getEndOfString(s);
    char *dest = copyIf(s, endSrc, s, (bool (*)(int)) isgraph);
    *dest = '\0';
}
