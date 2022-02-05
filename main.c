#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(100);
    printf("%p", v.data);

    return 0;
}
