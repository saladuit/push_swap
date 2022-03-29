/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   assert_empty_stdout.c                           |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:57:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 19:25:28 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>

void assert_empty_stdout()
{
	cr_assert_stdout_eq_str("");
	return ;
}
