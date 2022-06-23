/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_test.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/20 17:04:51 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 16:21:52 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_PUSH_SWAP
# define UNIT_PUSH_SWAP
# include <criterion/criterion.h>
# include <criterion/new/assert.h>
# include <criterion/redirect.h>
# include "push_swap.h"

void	redirect_all_std(void);
void	assert_empty_stdout();
void	assert_error_stdout();

void	argv_checker_test(const int len, const char **argv, const bool expected);
void	array_check_test(const int len, const int *integer, const bool expected);

void	init_integer_array_test(const int len, const char **argv, const int *expected);
#endif
