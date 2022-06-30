/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   init_stack_test.c                               |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 18:00:18 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/30 15:01:56 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	init_stack_test(const int len, const int *array)
{
	t_list	*stack = NULL;
	int number;
	size_t i = 0;

	stack = init_stack(len, array);
	while(i < (size_t)len)
	{
		number = *(int *)stack->content;
		cr_assert_eq(number, array[i]);
		stack = stack->next;
		i++;
	}
	return ;
}
