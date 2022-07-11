/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   swap.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:09:58 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 16:06:36 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	swap_a(t_list *stack_a)
{
	ft_swap_nodes(stack_a);
	ft_putendl_fd(SWAP_A, STDOUT_FILENO);
}

void	swap_b(t_list *stack_b)
{
	ft_swap_nodes(stack_b);
	ft_putendl_fd(SWAP_B, STDOUT_FILENO);
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	ft_swap_nodes(stack_a);
	ft_swap_nodes(stack_b);
	ft_putendl_fd(SWAP_AB, STDOUT_FILENO);
}
