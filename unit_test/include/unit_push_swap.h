/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_push_swap.h                                |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 14:48:48 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_PUSH_SWAP
# define UNIT_PUSH_SWAP
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <criterion/internal/redirect.h>
# include <criterion/internal/test.h>
# include <criterion/new/assert.h>
# include "/Users/safoh/Documents/Projects_Codam/push_swap/include/push_swap.h"
# include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"

void redirect_all_stdout(void);
void assert_empty_stdout();
void assert_error_stdout();

#endif
