/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   swap_top_list_test.c                            |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/01 15:51:53 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/04 10:20:27 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	swap_top_list_test(const size_t size, const int *input, const int *expected)
{
	t_list *stack;

	stack = init_stack(size, input);
	swap_top_list(stack);
	cr_assert(eq(int[size], (int *)input,(int *)expected));
	return ;
}
