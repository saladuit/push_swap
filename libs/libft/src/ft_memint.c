/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_memint.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 16:36:29 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/08 16:38:02 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memint(int *arr, int d, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == d)
			return (arr + d);
		i++;
	}
	return (NULL);
}
