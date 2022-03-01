add_library(tasks 5d/5d.c
        5d/tests/5d-test.c
        5e/5e.c
        5e/tests/5e-test.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)
target_link_libraries(tasks string)