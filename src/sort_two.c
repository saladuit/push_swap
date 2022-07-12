/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_two.c                                      |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:24:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 16:52:49 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	sort_two(t_list **stack_a)
{
		swap_a(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = *(int *)(*stack_a)->content;
	mid = *(int *)(*stack_a)->next->content;
	bot = *(int *)(*stack_a)->next->next->content;
	if (top > mid && mid < bot && top < bot)
		swap_a(stack_a);
	else if (top > mid && mid > bot && top > bot)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (top > mid && mid < bot && top > bot)
		rotate_a(stack_a);
	else if (top < mid && mid > bot && top < bot)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (top < mid && mid > bot && top > bot)
		rev_rotate_a(stack_a);
}

void	sort_four(t_list **stack_a)
{
	t_list *stack_b;

	stack_b = NULL;
	push_a_to_b(&stack_b, stack_a);
	sort_three(stack_a);
	push_b_to_a(stack_a, &stack_b);
	sort_three(stack_a);
	return ;
}

void	sort_five(t_list **stack_a)
{
	t_list *stack_b;

	stack_b = NULL;
	push_a_to_b(&stack_b, stack_a);
	push_a_to_b(&stack_b, stack_a);
	sort_three(stack_a);
	push_b_to_a(stack_a, &stack_b);
	sort_three(stack_a);
	push_b_to_a(stack_a, &stack_b);
	sort_three(stack_a);
	return ;
}
