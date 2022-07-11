/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:45:57 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 17:04:30 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

Test(argv_checker, fixed)
{
	argv_checker_test(1, ((const char *[]){""}), false);
	argv_checker_test(1, ((const char *[]){"1"}), true);
	argv_checker_test(1, ((const char *[]){"a"}), false);
/*tests that don't fail the project */
	argv_checker_test(2, ((const char *[]){"1", "2"}), true);
	argv_checker_test(2, ((const char *[]){"1", "+2"}), true);
	argv_checker_test(1, ((const char *[]){"10+-"}), false);
	argv_checker_test(9, ((const char *[]){"1", "2", "3", "4", "5", "6", "7", "8", "9"}), true);
	argv_checker_test(2, ((const char *[]){"1", "a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "1a"}), false);
	argv_checker_test(2, ((const char *[]){"1", "\n"}), false);
	argv_checker_test(2, ((const char *[]){"1", " 2"}), false);
	argv_checker_test(2, ((const char *[]){"1", " "}), false);
}

Test(init_integer_array_test, fixed)
{
	init_integer_array_test(1, ((const char *[]){"1"}), ((const int []){1}));
	init_integer_array_test(1, ((const char *[]){"+2147483648"}), NULL);
/*tests that don't fail the project */
/*I wasn't able to test the existance of integer array */
	init_integer_array_test(1, ((const char *[]){"0"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"-00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"+00"}), ((const int []){0}));
	init_integer_array_test(1, ((const char *[]){"00-"}), NULL);
	init_integer_array_test(1, ((const char *[]){"000001"}), ((const int []){1}));
	init_integer_array_test(1, ((const char *[]){"+2147483647"}), ((const int []){2147483647}));
	init_integer_array_test(1, ((const char *[]){"--+2147483647"}), NULL);
	init_integer_array_test(1, ((const char *[]){"-2147483648"}), ((const int []){-2147483648}));
	init_integer_array_test(1, ((const char *[]){"+-2147483648"}), NULL);
	init_integer_array_test(1, ((const char *[]){"2147483648"}), NULL);
	init_integer_array_test(2, ((const char *[]){"1", "2"}), ((const int []){1, 2}));
}

// Is the list already sorted and does it contain double numbers
Test(array_check, fixed)
{
	array_check_test(1, ((const int []){0}), SORTED);
	array_check_test(2, ((const int []){0, 1}), SORTED);
	array_check_test(2, ((const int []){1, 0}), NOT_SORTED);
	array_check_test(2, ((const int []){0, 0}), DOUBLE);
}

Test(make_positive, fixed)
{
	make_positive_test(1, ((int []){-1}), ((const int []){0}));
	make_positive_test(2, ((int []){-1, -500}), ((const int []){1, 0}));
	make_positive_test(5, ((int []){40, -10, -5, 0, -1}), ((const int []){4, 0, 1, 3, 2}));
	make_positive_test(3, ((int []){2, 3, 1}), ((const int []){1, 2, 0}));
}

//Test(parse_argv_to_array, fixed)
//{
//	parse_argv_to_array_test(1, (const char *[]){"1"}, (const int []){1});
//	parse_argv_to_array_test(1, (const char *[]){"a"}, NULL);
//}

Test(init_stack, fixed)
{
	init_stack_test(2, ((const int []){1, 2}));
}
////////////////////////////////////////////////////////////////////////////////
//			ACTIONS
////////////////////////////////////////////////////////////////////////////////
//Test(ft_swap_nodes_test, fixed, .init=redirect_all_std)
//{
//	ft_swap_nodes_test(2, ((const int []){10, 1}), ((const int []){1, 10}));
//	ft_swap_nodes_test(3, ((const int []){1, 10, 1}), ((const int []){10, 1, 1}));
//}

//Test(push_top_node, fixed, .init=redirect_all_std)
//{
//	push_top_node_test(1, 0, \
//			((const int []){10}), ((const int []){}), \
//			((const int []){}), ((const int []){10}));
//	push_top_node_test(2, 1, \
//			((const int []){10, 1}), ((const int []){1}), \
//			((const int []){1}), ((const int []){10, 1}));
//	push_top_node_test(0, 2, \
//			((const int []){}), ((const int []){10, 1}), \
//			((const int []){}), ((const int []){10, 1}));
//}

//Test(roatate_list, fixed, .init=redirect_all_std)
//{
//	rotate_list_test(0, ((const int []){}), ((const int []){}));
//	rotate_list_test(1, ((const int []){10}), ((const int []){10}));
//	rotate_list_test(2, ((const int []){10, 1}), ((const int []){1, 10}));
//	rotate_list_test(3, ((const int []){10, 2, 1}), ((const int []){2, 1, 10}));
//}
//
//Test(rev_rotate_list, fixed, .init=redirect_all_std)
//{
//	rev_rotate_list_test(0, ((const int []){}), ((const int []){}));
//	rev_rotate_list_test(1, ((const int []){10}), ((const int []){10}));
//	rev_rotate_list_test(2, ((const int []){10, 1}), ((const int []){1, 10}));
//	rev_rotate_list_test(3, ((const int []){10, 2, 1}), ((const int []){1, 10, 2}));
//}
////////////////////////////////////////////////////////////////////////////////
//			PROGRAM
////////////////////////////////////////////////////////////////////////////////
Test(push_swap, fixed)
{
	push_swap_test(1, ((const char *[]){"1"}), true);
	push_swap_test(1, ((const char *[]){"-2147483649"}), false);
	push_swap_test(2, ((const char *[]){"2", "1"}), true);
	push_swap_test(2, ((const char *[]){"1", "1"}), false);
	push_swap_test(2, ((const char *[]){"99999999999999999999", "1"}), false);
}
