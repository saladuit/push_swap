/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 16:27:47 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/safoh/Documents/Projects_Codam/push_swap/unit_test/include/unit_push_swap.h"
#include "unit_push_swap.h"

/* ************************************************************************** */
TestSuite(check_argc, .init=redirect_all_stdout);

Test(check_argc, one_arg, .fini=assert_empty_stdout)
{
	cr_expect(count_check(1) == false);
}

Test(check_argc, two_arg, .fini=assert_error_stdout)
{
	cr_expect(count_check(2) == false);
}

Test(check_argc, more_than_two_arg, .fini=assert_empty_stdout)
{
	cr_expect(count_check(3) == true);
}
/* ************************************************************************** */
/*check for:*/
/*- int min & max*/
/*- double numbers*/
/*- already sorted*/
/*- non-numeric parameters*/
/*- no parameters sould display nothing*/
/*- check "-"*/
TestSuite(check_argv, .init=redirect_all_stdout);

Test(check_argv, NULL_pointer, .fini=assert_empty_stdout)
{
	cr_expect(var_check(NULL) == false);
}

Test(check_argv, one_number, .fini=assert_empty_stdout)
{
	char *string = "1";
	cr_expect(var_check(&string) == true);
}

Test(check_argv, one_char, .fini=assert_error_stdout)
{
	char *string = "a";
	cr_expect(var_check(&string) == false);
}

Test(check_argv, two_numbers_sorted, .fini=assert_empty_stdout)
{
	char *string[2] = {"1", "2"};
	cr_expect(var_check(string) == true);
}

Test(check_argv, two_numbers_unsorted, .fini=assert_empty_stdout)
{
	char *string[2] = {"2", "1"};
	cr_expect(var_check(string) == true);
}

Test(check_argv, invalid_char, .fini=assert_error_stdout)
{
	char *string[2] = {"a", "1"};
	cr_expect(var_check(string) == false);
}

Test(check_argv, inlvaid_char_second_arg, .fini=assert_error_stdout)
{
	char *string[2] = {"1", "a"};
	cr_expect(var_check(string) == false);
}

Test(check_argv, invalid_char_second_position, .fini=assert_error_stdout)
{
	char *string[2] = {"1a", "1"};
	cr_expect(var_check(string) == false);
}
Test(check_argv, invalid_char_random_position, .fini=assert_error_stdout)
{
	char *string[2] = {"a1", "1234a"};
	cr_expect(var_check(string) == false);
}
	/*char *string6[2] = {"1", "1a"};*/
	/*char *string7[2] = {"1", "-"};*/
	/*char *string8[3] = {"1", "2", "1"};*/
	/*char **string9;*/
