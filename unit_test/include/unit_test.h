/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_test.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/20 17:04:51 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 14:26:17 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H
# include <criterion/criterion.h>
# include <criterion/new/assert.h>
# include <criterion/redirect.h>
# include "push_swap.h"
# include "actions.h"
# include "sort.h"
# include "init.h"
# include "argv_checker.h"

void	redirect_all_std(void);
void	assert_empty_stdout();
void	assert_error_stdout();

void	argv_checker_test(const int len, const char **argv, const bool expected);
void	array_check_test(const int len, const int *integer, const int expected);

void	init_integer_array_test(const int len, const char **argv, const int *expected);
void	parse_argv_to_array_test(const int len, const char **argv, const int *expected);
void	init_stack_test(const int len, const int *array);
void	make_positive_test(const int len, int *input, const int *expected);
void	sort_array_test(const int len, const int *input, const int *expected);

void	push_top_node_test(const size_t size_a, const size_t size_b, \
		const int *input_a, const int *input_b, \
		const int *expected_a, const int *expected_b);
void	rotate_list_test(const size_t size_a, const int *input_a, const int *expected_a);
void	rev_rotate_list_test(const size_t size_a, const int *input_a, const int *expected_a);
void	swap_top_list_test(const size_t size, const int *input, const int *expected);
void	push_swap_test(const int len, const char **argv, const bool expected);
#endif
