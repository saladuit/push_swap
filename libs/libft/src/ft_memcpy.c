/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_memcpy.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 21:02:41 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src && dest == 0)
		return (NULL);
	while (i < n)
	{
		((int *)dest)[i] = ((int *)src)[i];
		i++;
	}
	return (dest);
}
