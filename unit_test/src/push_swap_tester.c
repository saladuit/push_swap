/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:45:57 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/29 21:57:52 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

//Test(crashes, fixed, .signal = SIGSEGV)
//{
//	argv_checker_test(0, NULL, false);
//	init_integer_array_test(0, NULL, NULL);
//	array_check_test(0, NULL, SORTED);
//	parse_argv_to_array_test(0, NULL, NULL);
//}

Test(argv_checker, fixed)
{
	argv_checker_test(1, ((const char *[]){""}), false);
	argv_checker_test(1, ((const char *[]){"1"}), true);
	argv_checker_test(1, ((const char *[]){"a"}), false);
/*tests that don't fail the project */
	argv_checker_test(2, ((const char *[]){"1", "2"}), true);
	argv_checker_test(1, ((const char *[]){"10+-"}), true);
	argv_checker_test(9, ((const char *[]){"1", "2", "3", "4", "5", "6", "7", "8", "9"}), true);
	argv_checker_test(2, ((const char *[]){"1", "a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "1a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "\n"}), false);
}

Test(init_integer_array_test, fixed)
{
	init_integer_array_test(1, ((const char *[]){""}), NULL);
	init_integer_array_test(1, ((const char *[]){"1"}), ((const int []){1}));
	init_integer_array_test(1, ((const char *[]){"+2147483648"}), NULL);
/*tests that don't fail the project */
/*I wasn't able to test the existance of integer array */
	init_integer_array_test(1, ((const char *[]){"0"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"-00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"+00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"000001"}), ((const int []){1}));
	init_integer_array_test(1, ((const char *[]){"+2147483647"}), ((const int []){2147483647}));
	init_integer_array_test(1, ((const char *[]){"--+2147483647"}), NULL);
	init_integer_array_test(1, ((const char *[]){"-2147483648"}), ((const int []){-2147483648}));
	init_integer_array_test(1, ((const char *[]){"+-2147483648"}), NULL);
	init_integer_array_test(1, ((const char *[]){"2147483648"}), NULL);
	init_integer_array_test(2, ((const char *[]){"1", "2"}), ((const int []){1, 2}));
	init_integer_array_test(3, ((const char *[]){"1", "", "2"}), NULL);
}

// Is the list already sorted and does it contain double numbers
Test(array_check, fixed)
{
	array_check_test(1, ((const int []){0}), SORTED);
	array_check_test(2, ((const int []){0, 1}), SORTED);
	array_check_test(2, ((const int []){1, 0}), NOT_SORTED);
	array_check_test(2, ((const int []){0, 0}), DOUBLE);
}

Test(parse_argv_to_array, fixed)
{
	parse_argv_to_array_test(1, (const char *[]){"1"}, (const int []){1});
	parse_argv_to_array_test(1, (const char *[]){"a"}, NULL);
}

Test(push_swap, fixed)
{
	push_swap_test(1, ((const char *[]){"1"}), true);
	push_swap_test(2, ((const char *[]){"1", "1"}), false);
	push_swap_test(2, ((const char *[]){"99999999999999999999", "1"}), false);
}

Test(init_stack_a, fixed)
{
	init_stack_test(2, ((const int []){1, 2}));
}

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
