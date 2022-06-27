/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_joinmatrix.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 15:43:20 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/27 16:26:53 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinmatrix(const char **matrix, size_t count)
{
	size_t	total_len;
	size_t i;
	char	*result;

	if (matrix == NULL)
		return ("(null)\n");
	if (count == 0)
		return ("count == 0\n");
	total_len = count - 1;
	total_len += ft_matrixlen(matrix, count);
	result = ft_calloc(total_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count - 1)
	{
		result = ft_strjoin(result, matrix[i]);
		result = ft_strjoin(result, " ");
		i++;
    }
	result = ft_strjoin(result, matrix[count - 1]);
	return (result);
}
