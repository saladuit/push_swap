/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   rotate.c                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 15:46:00 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:33:33 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	rotate_a(t_list **stack_a)
{
	ft_rotate_list(stack_a);
	ft_putendl_fd(ROTATE_A, STDOUT_FILENO);
}

void	rotate_b(t_list **stack_b)
{
	ft_rotate_list(stack_b);
	ft_putendl_fd(ROTATE_B, STDOUT_FILENO);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_list(stack_a);
	ft_rotate_list(stack_b);
	ft_putendl_fd(ROTATE_AB, STDOUT_FILENO);
}
