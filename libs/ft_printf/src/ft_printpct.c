/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpct.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:23:54 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:17:34 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printpct(size_t *len)
{
	ft_putchar_fd('%', 1);
	*len += 1;
	return ;
}
