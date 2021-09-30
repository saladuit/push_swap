/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchr.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:29:48 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:15:57 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printchr(size_t *len, int c)
{
	ft_putchar_fd(c, 1);
	*len += 1;
	return ;
}
