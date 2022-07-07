/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_rotate_list.c                                |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/07 20:28:56 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 20:40:09 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 	*ft_rotate_list(t_list **lst, t_list *lnew)
{
	t_list	*tmp;

	tmp = lnew->next;
	ft_lstadd_front(lst, lnew);
	lnew->next = NULL;
	return (tmp);
}
