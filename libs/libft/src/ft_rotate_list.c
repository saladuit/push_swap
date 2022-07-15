/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_rotate_list.c                                |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/07 20:28:56 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/15 17:03:48 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_list(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}
