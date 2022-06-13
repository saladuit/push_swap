/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/13 17:50:41 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_PUSH_SWAP
# define UNIT_PUSH_SWAP
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <criterion/logging.h>
# include <criterion/internal/redirect.h>
# include <criterion/internal/test.h>
# include <criterion/new/assert.h>
# include "push_swap.h"

void	redirect_all_std(void);
void	assert_empty_stdout();
void	assert_error_stdout();

void	argc_checker_test(const int argc, const bool expected);
void	argv_checker_test(const int len, char **argv, const bool expected);

#endif
