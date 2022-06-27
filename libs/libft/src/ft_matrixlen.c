/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_matrixlen.c                                  |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 15:37:10 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/27 16:20:25 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matrixlen(const	char **matrix, size_t count)
{
	size_t total_len;
	size_t i;

	total_len = 0;
	i = 0;
	while (i < count)
	{
		total_len = ft_strlen(matrix[i]);
		i++;
	}
	return (total_len);
}
