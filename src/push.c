/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 15:42:47 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 15:52:02 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	push_b(t_list *stack_a, t_list *stack_b)
{
	ft_push_node(&stack_a, &stack_b); 
	ft_putendl_fd(PUSH_B, STDOUT_FILENO);
}

void	push_a(t_list *stack_a, t_list *stack_b)
{
	ft_push_node(&stack_b, &stack_a); 
	ft_putendl_fd(PUSH_A, STDOUT_FILENO);
}
