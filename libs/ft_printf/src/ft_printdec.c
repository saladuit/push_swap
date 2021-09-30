/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdec.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:28:42 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:16:21 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printdec(size_t *len, int n)
{
	ft_putnbr_fd(n, 1);
	*len += ft_numlen(n);
	if (n < 0)
		(*len)++;
	return ;
}
