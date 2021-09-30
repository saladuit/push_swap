/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:25 by saladin       #+#    #+#                 */
/*   Updated: 2021/07/26 16:30:03 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

static char	*ft_strnew(size_t size)
{
	char		*str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*dest;
	size_t		len;

	if ((s == 0) || (f == 0))
		return (0);
	len = ft_strlen(s);
	dest = ft_strnew(len);
	if (!dest)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dest[len] = f(len, s[len]);
		len++;
	}
	return (dest);
}
