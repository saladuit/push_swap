/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                                 :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:18:40 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/25 02:09:24 by saladuit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

Test(argv_checker, fixed_tests)
{
	argv_checker_test(0, NULL, false);
	argv_checker_test(1, ((const char *[]){""}), false);
	argv_checker_test(1, ((const char *[]){"1"}), true);
	argv_checker_test(1, ((const char *[]){"a"}), false);
/*tests that don't fail the project */
	argv_checker_test(2, ((const char *[]){"1", "2"}), true);
	argv_checker_test(2, ((const char *[]){"10+-"}), true);
	argv_checker_test(9, ((const char *[]){"1", "2", "3", "4", "5", "6", "7", "8", "9"}), true);
	argv_checker_test(2, ((const char *[]){"1", "a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "1a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "\n"}), false);
}

Test(init_integer_array_test, fixed_tests)
{
	init_integer_array_test(0, NULL, NULL);
	init_integer_array_test(1, ((const char *[]){""}), NULL);
	init_integer_array_test(1, ((const char *[]){"1"}), ((const int []){1}));
	init_integer_array_test(1, ((const char *[]){"+2147483648"}), NULL);
/*tests that don't fail the project */
/*I wasn't able to test the existance of integer array */
	init_integer_array_test(1, ((const char *[]){"0"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"-00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"+00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"+2147483647"}), ((const int []){2147483647}));
	init_integer_array_test(1, ((const char *[]){"--+2147483647"}), NULL);
	init_integer_array_test(1, ((const char *[]){"-2147483648"}), ((const int []){-2147483648}));
	init_integer_array_test(1, ((const char *[]){"+-2147483648"}), NULL);
	init_integer_array_test(1, ((const char *[]){"2147483648"}), NULL);
	init_integer_array_test(2, ((const char *[]){"1", "2"}), ((const int []){1, 2}));
	init_integer_array_test(3, ((const char *[]){"1", "", "2"}), ((const int []){1, 2}));
}

// Is the list already sorted and does it contain double numbers
Test(array_check, fixed_tests)
{
	array_check_test(1, ((const int []){0}), SORTED);
	array_check_test(2, ((const int []){0, 1}), SORTED);
	array_check_test(2, ((const int []){1, 0}), NOT_SORTED);
	array_check_test(2, ((const int []){0, 0}), DOUBLE);
}

Test(parse_argv_to_array, fixed_tests)
{
	parse_argv_to_array_test(0, NULL, NULL);
	parse_argv_to_array_test(1, (const char *[]){"1"}, (const int []){1});
}


/*[> ************************************************************************** <]*/
/*TestSuite(init_stack, .init=redirect_stdout_to_stderr);*/
/*[> ************************************************************************** <]*/
/*bool	test_init_stack(int *expected)*/
/*{*/
	/*t_list	*stack_a = NULL;*/
	/*int number;*/
	/*int len = 0;*/
	/*size_t i = 0;*/

	/*if (expected)*/
		/*while (expected[len])*/
			/*len++;*/
	/*stack_a = init_stack(len, expected, stack_a);*/
	/*if (stack_a == NULL)*/
	/*{*/
		/*if (expected)*/
			/*cr_log_error("Stack_init_setup failed\n");*/
		/*return (false);*/
	/*}*/
	/*while(i < (size_t)len)*/
	/*{*/
		/*number = *(int *)stack_a->content;*/
		/*if(number != expected[i])*/
			/*return (false);*/
		/*stack_a = stack_a->next;*/
		/*i++;*/
	/*}*/
	/*ft_lstclear(&stack_a, NULL);*/
	/*return (true);*/
/*}*/

/*Test(init_stack, null_pointer)*/
/*{*/
	/*int *expected = NULL;*/
	
	/*cr_assert(test_init_stack(expected) == false);*/
	/*cr_assert_stderr_eq_str("Error\n");*/
/*}*/

/*Test(init_stack, one_valid_int)*/
/*{*/
	/*int	expected[] = {1, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, MAX_int)*/
/*{*/
	/*int	expected[] = {2147483647, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, double_MAXMAX_int)*/
/*{*/
	/*int	expected[] = {2147483647, -2147483648, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, double_MAX_int)*/
/*{*/
	/*int	expected[] = {2147483647, 2147483647, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, MIN_int)*/
/*{*/
	/*int	expected[] = {-2147483648, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, two_valid_int)*/
/*{*/
	/*int	expected[] = {1, 2, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, three_valid_int)*/
/*{*/
	/*int	expected[] = {1, 2, 3, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, three_valid_negint)*/
/*{*/
	/*int	expected[] = {-1, -2, -3, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, rev_three_valid_negint)*/
/*{*/
	/*int	expected[] = {-3, -2, -1, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/

/*Test(init_stack, 0_three_valid_negint)*/
/*{*/
	/*int	expected[] = {-3, 0, -1, '\0'};*/
	/*cr_assert(test_init_stack(expected) == true);*/
	/*cr_assert_stderr_eq_str("");*/
/*}*/
/*[> ************************************************************************** <]*/
/*TestSuite(sa, .init=redirect_stdout_to_stderr);*/
/*[> ************************************************************************** <]*/

/*t_list*	setup_stack_a(const int* initial, size_t initial_len)*/
/*{*/
	/*t_list *stack_a = NULL;*/
	/*cr_assert(initial != NULL);*/
	/*stack_a = init_stack(initial_len, initial, stack_a);*/
	/*cr_assert(stack_a != NULL);*/
	/*return stack_a;*/
/*}*/

/*void	destroy_stack_a(t_list* stack_a)*/
/*{*/
	/*ft_lstclear(&stack_a, NULL);*/
/*}*/

/*bool	compare_stack_against_array(t_list* stack_a, const int *expected, size_t expected_len)*/
/*{*/
	/*size_t i = 0;*/
	/*int number;*/
	/*while(i < expected_len)*/
	/*{*/
		/*number = *(int *)stack_a->content;*/
		/*if(number != expected[i])*/
			/*return false;*/
		/*stack_a = stack_a->next;*/
		/*i++;*/
	/*}*/
	/*return true;*/
/*}*/

/*Test(sa, basic_input)*/
/*{*/
	/*const int initial[] = {1, 2};*/
	/*const int	expected[] = {2, 1};*/

	/*const size_t initial_len = sizeof(initial) / sizeof(*initial);*/
	/*const size_t expected_len = sizeof(expected) / sizeof(*expected);*/

	/*t_list* stack_a = setup_stack_a(initial, initial_len);*/
	/*sa(stack_a);*/

	/*bool result = compare_stack_against_array(stack_a, expected, expected_len);*/
	/*destroy_stack_a(stack_a);*/

	/*cr_expect(result == true);*/
	/*cr_expect_stdout_eq_str("sa\n");*/
/*}*/
