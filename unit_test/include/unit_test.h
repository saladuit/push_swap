/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/17 16:34:57 by safoh            ###   ########.fr       */
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

void	init_integer_array_tester(const int len, const char **argv, const int *expected);
#endif
