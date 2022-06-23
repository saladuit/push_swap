/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_calloc.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 15:11:59 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	p = (void *)malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}
