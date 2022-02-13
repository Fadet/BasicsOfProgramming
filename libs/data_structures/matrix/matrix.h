//
// Created by User on 13.02.2022.
//

#ifndef LABS_LIBS_MATRIX_H
#define LABS_LIBS_MATRIX_H

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

#endif //LABS_LIBS_MATRIX_H
