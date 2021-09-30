/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printudec.c                                  |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:27:52 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:17:26 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printudec(size_t *len, unsigned int n)
{
	ft_putuint_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}
