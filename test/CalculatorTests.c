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
    ck_assert_str_eq("X", add("V", "V"));
    ck_assert_str_eq("L", add("XXX", "XX"));
    ck_assert_str_eq("C", add("L", "L"));
    ck_assert_str_eq("D", add("CCC", "CC"));
    ck_assert_str_eq("M", add("D", "D"));
}
END_TEST

START_TEST(test_add_numbers_resulting_in_need_to_compact_with_subtraction)
{
    ck_assert_str_eq("IV", add("II", "II"));
    ck_assert_str_eq("IX", add("VII", "II"));
    ck_assert_str_eq("XL", add("XX", "XX"));
    ck_assert_str_eq("CD", add("CC", "CC"));
    ck_assert_str_eq("XC", add("LX", "XXX"));
    ck_assert_str_eq("CM", add("DC", "CCC"));
}
END_TEST

START_TEST(test_add_numbers_resulting_in_many_subtractions)
{
    //1999 = MCMXDIX
    ck_assert_str_eq("MCMXCIX", add("MDCCLXXVII", "CCXXII"));
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
    tcase_add_test(addRomanTestCase, test_add_numbers_resulting_in_need_to_compact_with_subtraction);
    tcase_add_test(addRomanTestCase, test_add_numbers_resulting_in_many_subtractions);
    suite_add_tcase(suite, addRomanTestCase);

    return suite;
}
