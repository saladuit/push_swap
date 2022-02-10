/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_lstadd_back.c                                |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/02/09 14:42:04 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/02/09 16:22:02 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (*lst == NULL)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	return ;
}
