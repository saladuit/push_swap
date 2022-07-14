/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_lstiter.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:58:45 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size;

	size = ft_lstsize(lst);
	while (size)
	{
		f(lst->content);
		lst = lst->next;
		size--;
	}
	return ;
}
