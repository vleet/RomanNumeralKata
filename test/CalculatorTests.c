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

START_TEST(test_add_two_different_one_char_numbers_with_larger_number_on_right)
{
    ck_assert_str_eq("VI", add("I", "V"));
}
END_TEST

START_TEST(test_add_two_different_two_char_numbers)
{
    ck_assert_str_eq("CXVI", add("XI", "CV"));
}
END_TEST

START_TEST(test_add_numbers_resulting_in_multiple_of_same_numeral)
{
    ck_assert_str_eq("III", add("I", "II"));
}
END_TEST

START_TEST(test_add_numbers_requiring_grouping)
{
    ck_assert_str_eq("V", add("III", "II"));
}
END_TEST

Suite* calculatorTestsSuite(void) {
    Suite * suite = suite_create("Calculator Tests");
    TCase *addRomanTestCase = tcase_create("add");
    tcase_add_test(addRomanTestCase, test_add_two_different_one_char_numbers_with_larger_number_on_left);
    tcase_add_test(addRomanTestCase, test_add_two_different_one_char_numbers_with_larger_number_on_right);
    tcase_add_test(addRomanTestCase, test_add_two_different_two_char_numbers);
    tcase_add_test(addRomanTestCase, test_add_numbers_resulting_in_multiple_of_same_numeral);
    tcase_add_test(addRomanTestCase, test_add_numbers_requiring_grouping);
    suite_add_tcase(suite, addRomanTestCase);

    return suite;
}
