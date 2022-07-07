/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_rev_rotate_list.c                            |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/07 20:37:10 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 20:40:21 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_rev_rotate_list(t_list **lst, t_list *lnew)
{
	t_list	*tmp;

	tmp = lnew->next;
	ft_lstadd_back(lst, lnew);
	lnew->next = NULL;
	return (tmp);
}
