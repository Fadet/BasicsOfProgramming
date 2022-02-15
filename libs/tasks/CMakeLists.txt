add_library(tasks 5d/5d.c
        5d/tests/5d-test.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)