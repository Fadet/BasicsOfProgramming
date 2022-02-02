add_library(data_structures
        vector/vector.c
        vector/tests/vector-test.c)

target_link_libraries(data_structures algorithms)