/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_strbapi.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:53:17 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_strbapi(char const *s, bool (*f)(int))
{
	size_t	i;
	size_t	len;

	if ((s == 0) || (f == 0))
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (!f(s[i]))
			return (false);
		i++;
	}
	return (true);
}
