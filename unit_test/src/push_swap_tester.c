/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/02 16:21:23 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/safoh/Documents/Projects_Codam/push_swap/unit_test/include/unit_push_swap.h"
#include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <string.h>

/* ************************************************************************** */
TestSuite(check_argc, .init=redirect_all_stdout);
/* ************************************************************************** */

Test(check_argc, one_arg)
{
	cr_expect(count_check(1) == false);
	cr_assert_stdout_eq_str("");
}

Test(check_argc, two_arg)
{
	cr_expect(count_check(2) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argc, more_than_two_arg)
{
	cr_expect(count_check(3) == true);
	cr_assert_stdout_eq_str("");
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
/* ************************************************************************** */

Test(check_argv, NULL_pointer)
{
	cr_expect(var_check(0, NULL) == false);
}

Test(check_argv, one_number)
{
	char *string[] = {"1", NULL};
	cr_expect(var_check(1, string) == true);
	cr_assert_stdout_eq_str("");
}

Test(check_argv, one_char)
{
	char *string[] = {"a", NULL};
	cr_expect(var_check(1, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, two_numbers_sorted)
{
	char *string[] = {"1", "2", NULL};
	cr_expect(var_check(2, string) == true);
	cr_assert_stdout_eq_str("");
}

Test(check_argv, two_numbers_unsorted)
{
	char *string[] = {"2", "1", NULL};
	cr_expect(var_check(2, string) == true);
	cr_assert_stdout_eq_str("");
}

Test(check_argv, invalid_char)
{
	char *string[] = {"a", "1", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_char_second_arg)
{
	char *string[] = {"1", "a", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_char_second_position)
{
	char *string[] = {"1a", "1", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}
Test(check_argv, invalid_char_random_position)
{
	char *string[] = {"a1", "1234a", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_char_nl)
{
	char *string[] = {"\n", "2", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_char_specialchar)
{
	char *string[] = {"1", "-", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_char_tab)
{
	char *string[] = {"1", "\t", NULL};
	cr_expect(var_check(2, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_nullterminator)
{
	char *string[] = {"4", "\0", "3", NULL};
	cr_expect(var_check(3, string) == true);
	cr_assert_stdout_eq_str("");
}

Test(check_argv, invalid_nullterminator_check)
{
	char *string[] = {"4", "0", "3", NULL};
	cr_expect(var_check(3, string) == true);
	cr_assert_stdout_eq_str("");
}

Test(check_argv, invalid_3x_nullterminator)
{
	char *string[] = {"\\0", "2", "\0", NULL};
	cr_expect(var_check(3, string) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(check_argv, invalid_nullterminator_afternum)
{
	char *string[] = {"4", "1\0", "0", NULL};
	cr_expect(var_check(3, string) == true);
	cr_assert_stdout_eq_str("");
}

/* ************************************************************************** */
TestSuite(argvtoarray, .init=redirect_all_stdout);
/* ************************************************************************** */

Test(argvtoarray, NULL_values)
{
	cr_assert(argvtoarray(0, NULL, NULL) == NULL);
	cr_assert_stdout_eq_str("Error\n");
}

Test(argvtoarray, one_valid_argv)
{
	cr_assert(argvtoarray(0, NULL, NULL) == NULL);
	cr_assert_stdout_eq_str("Error\n");
}
/*Is the list already sorted and does it contain double numbers*/
/* ************************************************************************** */
TestSuite(array_check, .init=redirect_all_stdout);
/* ************************************************************************** */

bool	test_array_check(int *expected)
{
	int len;

	len = 0;
	if (expected)
		while (expected[len])
			len++;
	if (array_check(len, expected) == false)
		return (false);
	return (true);
}

Test(array_check, NULL_values)
{
	cr_assert(test_array_check(NULL) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(array_check, one_nemb_sorted)
{
	int	expected[] = {1, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(array_check, two_nemb_unsorted)
{
	int	expected[] = {2, 1, '\0'};
	cr_assert(test_array_check(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(array_check, two_nemb_double)
{
	int	expected[] = {2, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(array_check, three_nemb_double_middle)
{
	int	expected[] = {2, 3, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(array_check, three_nemb_double_back)
{
	int	expected[] = {3, 2, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(array_check, three_nemb_double_front)
{
	int	expected[] = {2, 2, 3, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}


/* ************************************************************************** */
TestSuite(init_stack_a, .init=redirect_all_stdout);
/* ************************************************************************** */

bool	test_init_stack_a(int *expected)
{
	t_list	*stack_a = NULL;
	int number;
	int len = 0;
	size_t i = 0;

	if (expected)
		while (expected[len])
			len++;
	stack_a = init_stack_a(len, expected, stack_a);
	if (stack_a == NULL)
		return (false);
	while(i < (size_t)len)
	{
		number = *(int *)stack_a->content;
		if(number != expected[i])
			return (false);
		stack_a = stack_a->next;
		i++;
	}
	ft_lstclear(&stack_a, NULL);
	return (true);
}

Test(init_stack_a, null_pointer)
{
	int *expected = NULL;
	
	cr_assert(test_init_stack_a(expected) == false);
	cr_assert_stdout_eq_str("Error\n");
}

Test(init_stack_a, one_valid_int)
{
	int	expected[] = {1, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, MAX_int)
{
	int	expected[] = {2147483647, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, double_MAXMAX_int)
{
	int	expected[] = {2147483647, -2147483648, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, double_MAX_int)
{
	int	expected[] = {2147483647, 2147483647, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, MIN_int)
{
	int	expected[] = {-2147483648, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, two_valid_int)
{
	int	expected[] = {1, 2, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, three_valid_int)
{
	int	expected[] = {1, 2, 3, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, three_valid_negint)
{
	int	expected[] = {-1, -2, -3, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, rev_three_valid_negint)
{
	int	expected[] = {-3, -2, -1, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}

Test(init_stack_a, 0_three_valid_negint)
{
	int	expected[] = {-3, 0, -1, '\0'};
	cr_assert(test_init_stack_a(expected) == true);
	cr_assert_stdout_eq_str("");
}
