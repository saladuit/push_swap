/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cnvspc.c                                     |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:30:39 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/22 11:43:00 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_cnvspc(int c, size_t *len, va_list ap)
{
	if (c == 'c')
		ft_printchr(len, va_arg(ap, int));
	else if (c == 's')
		ft_printstr(len, va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		ft_printdec(len, va_arg(ap, int));
	else if (c == 'u')
		ft_printudec(len, va_arg(ap, unsigned int));
	else if (c == 'x')
		ft_printhex(len, va_arg(ap, unsigned int));
	else if (c == 'X')
		ft_printhe_x(len, va_arg(ap, unsigned int));
	else if (c == 'p')
		ft_printpnt(len, va_arg(ap, unsigned long));
	else if (c == '%')
		ft_printpct(len);
	return ;
}
