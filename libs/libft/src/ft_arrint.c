/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_arrint.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 14:34:10 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 14:35:16 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_arrint(int *array, int num, int len)
{
	size_t i;
	
	i = 0;
	while (i < (size_t)len)
	{
		if (array[i] == num)
			return (array + i);
		i++;
	}
	return (NULL);
}
