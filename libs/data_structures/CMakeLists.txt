add_library(data_structures
        vector/vector.c
        vector/tests/vector-test.c
        vectorVoid/vectorVoid.c
        vectorVoid/tests/vectorVoid-test.c
        matrix/matrix.c
        matrix/tests/matrix-test.c)

target_link_libraries(data_structures algorithms)