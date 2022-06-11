/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_push_swap.h                                   :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/11 19:14:50 by safoh            ###   ########.fr       */
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

void	redirect_all_std(void);
void	assert_empty_stdout();
void	assert_error_stdout();

void	check_argc_test(const int argc, const bool expected, const char *error_output);
#endif
