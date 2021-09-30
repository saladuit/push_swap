/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhe_x.c                                  |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:26:48 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/28 16:17:39 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

void	ft_printhe_x(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_strtoupper(result);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}
