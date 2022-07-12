/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   rev_rotate.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 15:48:53 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 14:54:18 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */


#include "actions.h"


void	rev_rotate_a(t_list **stack_a)
{
	ft_rev_rotate_list(stack_a);
	ft_putendl_fd(REV_ROTATE_A, STDOUT_FILENO);
}

void	rev_rotate_b(t_list **stack_b)
{
	ft_rev_rotate_list(stack_b);
	ft_putendl_fd(REV_ROTATE_B, STDOUT_FILENO);
}

void	rev_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate_list(stack_a);
	ft_rev_rotate_list(stack_b);
	ft_putendl_fd(REV_ROTATE_AB, STDOUT_FILENO);
}
