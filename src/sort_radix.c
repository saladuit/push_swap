/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_radix.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:23:53 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 14:15:26 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	sort_radix(int len_a, t_list *stack_a)
{
	t_list *stack_b;
	int max_num; // the biggest number in a is stack_size - 1
	int max_bits; // how many bits for max_num 
	int len_b;
	int num;
	int i;
	int j;

	stack_b = NULL;
	len_b = 0;
	max_num = len_a - 1;
	max_bits = bit_count(max_num);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		while (j < len_a)
		{
			num = *(int *)stack_a->content;
			if (((num >> i)&1) == 1)
				rotate_a(&stack_a);
			else 
				push_a_to_b(&stack_b, &stack_a);
			j++;
		}
		len_b = ft_lstsize(stack_b);
		while (len_b)
		{
			push_b_to_a(&stack_a, &stack_b);
			len_b--;
		}
		i++;
	}
}
