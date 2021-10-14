/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_lstadd_front.c                               |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/10/13 11:34:06 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2021/10/14 13:40:41 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}
