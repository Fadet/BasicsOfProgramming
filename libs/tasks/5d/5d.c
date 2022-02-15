//
// Created by user on 15.02.2022.
//

#include "5d.h"

void swapRowsWithMaxMinElements(matrix m) {
    position posMin = getMinValuePos(m);
    position posMax = getMaxValuePos(m);

    swapRows(m, posMin.rowIndex, posMax.rowIndex);
}