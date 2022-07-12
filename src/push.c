/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/11 15:42:47 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 14:10:34 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	push_a_to_b(t_list **dest, t_list **source)
{
	ft_push_node(dest, source); 
	ft_putendl_fd(PUSH_B, STDOUT_FILENO);
}

void	push_b_to_a(t_list **dest, t_list **source)
{
	ft_push_node(dest, source); 
	ft_putendl_fd(PUSH_A, STDOUT_FILENO);
}
