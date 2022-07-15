/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_swap_nodes.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/07 21:31:50 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/15 16:26:35 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_nodes(t_list **stack)
{
	t_list *temp;

	temp = *stack;
	ft_swap(temp->content, temp->next->content);
}
