#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "CalculatorTests.h"
#include "../src/Calculator.h"

START_TEST(test_add_two_different_one_char_numbers_with_larger_number_on_left)
{
    ck_assert_str_eq("VI", add("V", "I"));
}
END_TEST


Suite* calculatorTestsSuite(void) {
    Suite * suite = suite_create("Calculator Tests");
    TCase *addRomanTestCase = tcase_create("add");
    tcase_add_test(addRomanTestCase, test_add_two_different_one_char_numbers_with_larger_number_on_left);
    suite_add_tcase(suite, addRomanTestCase);

    return suite;
}
