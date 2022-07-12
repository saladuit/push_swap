/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_five.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 14:35:12 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 16:44:01 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "sort.h"

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
