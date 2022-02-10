/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_lstsize.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/10/14 16:29:08 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/02/09 13:11:33 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
