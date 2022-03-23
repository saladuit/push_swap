/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strbapi.c                                    |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:25 by saladin       #+#    #+#                 */
/*   Updated: 2022/03/23 22:26:42 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_strbapi(char const *s, int (*f)(int))
{
	size_t		i;

	if ((s == 0) || (f == 0))
		return (0);
	i = ft_strlen(s);
	while (s[i])
	{
		if(!f(s[i]))
			return (false);
		i++;
	}
	return (true);
}
