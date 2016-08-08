#include <stdlib.h>
#include <check.h>
#include "CalculatorTests.h"

int main(){
    int numberOfFailedTests;
    Suite* calculatorSuite = calculatorTestsSuite();
    SRunner *suiteRunner = srunner_create(calculatorSuite);
    srunner_run_all(suiteRunner, CK_VERBOSE);

    numberOfFailedTests = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);
    return (numberOfFailedTests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
