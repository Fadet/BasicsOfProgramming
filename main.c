//#include "libs/data_structures/vector/tests/vector-test.h"
//#include "libs/data_structures/vectorVoid/tests/vectorVoid-test.h"
//#include "libs/data_structures/matrix/tests/matrix-test.h"
//#include "libs/tasks/5d/tests/5d-test.h"
//#include "libs/string/tests/string_-test.h"
//#include "libs/tasks/5e/tests/5e-test.h"

#include "libs/algorithms/sorts/tests/sorts-test.h"
#include <pthread.h>

void *timeExperimentThr(void *a) {
    timeExperiment();
}

int main() {
//    test_vector();
//    test_vectorVoid();
//    test_matrix();
//    test_5d();
//    test_string_();
//    test_5e();

    pthread_t timeExperimentThread;
    pthread_create(&timeExperimentThread, NULL,
                   timeExperimentThr, NULL);


    comparesExperiment();
//    timeExperiment();

    pthread_join(timeExperimentThread, NULL);

    return 0;
}
