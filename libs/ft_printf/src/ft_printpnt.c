/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpnt.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:26:09 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:17:31 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printpnt(size_t *len, unsigned long ul)
{
	char	*result;

	ft_putstr_fd("0x", 1);
	result = ft_ultoh(ul);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result) + 2;
	free(result);
	return ;
}
