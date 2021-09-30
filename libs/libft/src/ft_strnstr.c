/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:30 by saladin       #+#    #+#                 */
/*   Updated: 2021/07/27 14:47:52 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(little);
	if (little == NULL || *little == '\0' || len == 0)
	{
		if (*little == '\0')
			return ((char *)big);
		else
			return (NULL);
	}
	while (i < len)
	{
		if (!ft_strncmp(big + i, little, j) && i + j < len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
