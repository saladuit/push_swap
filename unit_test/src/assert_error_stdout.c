/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   assert_error_stdout.c                           |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/28 14:44:16 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 14:51:38 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/safoh/Documents/Projects_Codam/push_swap/unit_test/include/unit_push_swap.h"

void	assert_error_stdout(void)
{
	cr_expect_stdout_eq_str("error\n");
}
