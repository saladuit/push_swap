/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_three.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 14:39:02 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 15:51:08 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "actions.h"

void	sort_three(t_list *stack_a)
{
	int	top;
	int mid;
	int bot;
	
	top = *(int *)stack_a->content;
	mid = *(int *)stack_a->next->content;
	bot = *(int *)stack_a->next->next->content;
	if (top > mid && mid < bot && top < bot)
		swap_a(stack_a);
	if (top < mid && mid < bot && top < bot)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	if (top < mid && mid < bot && top < bot)
		rotate_a(stack_a);
	if (top < mid && mid < bot && top < bot)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else
		rev_rotate_a(stack_a);
}
