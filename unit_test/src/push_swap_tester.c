/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/29 17:39:55 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/safoh/Documents/Projects_Codam/push_swap/unit_test/include/unit_push_swap.h"
#include <criterion/logging.h>
#include <string.h>
/*#include "unit_push_swap.h"*/

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
	cr_expect(var_check(0, NULL) == false);
}

Test(check_argv, one_number, .fini=assert_empty_stdout)
{
	char *string[] = {"1", NULL};
	cr_expect(var_check(1, string) == true);
}

Test(check_argv, one_char, .fini=assert_error_stdout)
{
	char *string[] = {"a", NULL};
	cr_expect(var_check(1, string) == false);
}

Test(check_argv, two_numbers_sorted, .fini=assert_empty_stdout)
{
	char *string[] = {"1", "2", NULL};
	cr_expect(var_check(2, string) == true);
}

Test(check_argv, two_numbers_unsorted, .fini=assert_empty_stdout)
{
	char *string[] = {"2", "1", NULL};
	cr_expect(var_check(2, string) == true);
}

Test(check_argv, invalid_char, .fini=assert_error_stdout)
{
	char *string[] = {"a", "1", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_char_second_arg, .fini=assert_error_stdout)
{
	char *string[] = {"1", "a", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_char_second_position, .fini=assert_error_stdout)
{
	char *string[] = {"1a", "1", NULL};
	cr_expect(var_check(2, string) == false);
}
Test(check_argv, invalid_char_random_position, .fini=assert_error_stdout)
{
	char *string[] = {"a1", "1234a", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_char_nl, .fini=assert_error_stdout)
{
	char *string[] = {"\n", "2", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_char_specialchar, .fini=assert_error_stdout)
{
	char *string[] = {"1", "-", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_char_tab, .fini=assert_error_stdout)
{
	char *string[] = {"1", "\t", NULL};
	cr_expect(var_check(2, string) == false);
}

Test(check_argv, invalid_nullterminator, .fini=assert_error_stdout)
{
	char *string[] = {"4", "\0", "3", NULL};
	cr_expect(var_check(3, string) == false);
}

Test(check_argv, invalid_nullterminator_check, .fini=assert_empty_stdout)
{
	char *string[] = {"4", "0", "3", NULL};
	cr_expect(var_check(3, string) == true);
}

Test(check_argv, invalid_3x_nullterminator, .fini=assert_error_stdout)
{
	char *string[] = {"\\0", "2", "\0", NULL};
	cr_expect(var_check(3, string) == false);
}

Test(check_argv, invalid_nullterminator_afternum, .fini=assert_empty_stdout)
{
	char *string[] = {"4", "1\0", "0", NULL};
	cr_expect(var_check(3, string) == true);
}

TestSuite(init_stack_a, .init=redirect_all_stdout);

Test(init_stack_a, null_pointer, .init=assert_empty_stdout)
{
	cr_expect(init_stack_a(0, NULL) == NULL);
}

Test(init_stack_a, one_valid_char, .init=assert_empty_stdout)
{
	char *string[] = {"1", NULL};
	t_list	*stack_a;
	int argc;
	size_t i;

	argc = 1;
	i = 0;
	stack_a = init_stack_a(argc, string);
	while(i < (size_t)argc)
	{
		cr_expect(strcmp(stack_a->content, string[i]) == 0);
		stack_a = stack_a->next;
		i++;
	}
}

Test(init_stack_a, two_valid_char, .init=assert_empty_stdout)
{
	char *string[] = {"1", "2", NULL};
	int	expected[] = {1, 2, '\0'};
	t_list	*stack_a;
	int argc;
	size_t i;

	argc = 2;
	i = 0;
	stack_a = init_stack_a(argc, string);
	while(i < (size_t)argc)
	{
		cr_expect(((int*)(stack_a->content)) == 1);
		stack_a = stack_a->next;
		i++;
	}
}
