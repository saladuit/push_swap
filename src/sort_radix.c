/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_radix.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:23:53 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/15 18:26:12 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	helper(int len_a, t_list **stack_a, int i)
{
	t_list	*stack_b;
	int		j;
	int		num;

	j = 0;
	stack_b = NULL;
	while (j < len_a)
	{
		num = *(int *)(*stack_a)->content;
		if (((num >> i) & 1) == 1)
			rotate_a(stack_a);
		else
			push_a_to_b(&stack_b, stack_a);
		j++;
	}
	while (stack_b)
		push_b_to_a(stack_a, &stack_b);
}

void	sort_radix(int len_a, t_list **stack_a)
{
	int	max_num;
	int	max_bits;
	int	i;

	max_num = len_a - 1;
	max_bits = ft_bit_count(max_num);
	i = 0;
	while (i < max_bits)
	{
		helper(len_a, stack_a, i);
		i++;
	}
}
