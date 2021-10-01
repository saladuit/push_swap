/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                    |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:19 by saladin       #+#    #+#                 */
/*   Updated: 2021/07/26 15:34:31 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	res;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	res = 0;
	i = 0;
	if (size == 0)
		return (s_len);
	if (size > d_len)
		res = d_len + s_len;
	else
		res = s_len + size;
	while (i + d_len < size - 1 && src[i])
	{
		dst[i + d_len] = src[i];
		i++;
	}
	dst[i + d_len] = '\0';
	return (res);
}
