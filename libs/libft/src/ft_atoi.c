/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_atoi.c                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:59:09 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	init_atoi(const char *nptr, int *sign)
{
	size_t	len;

	len = 0;
	while (ft_isspace((int)nptr[len]))
		len++;
	if (nptr[len] == '-')
	{
		*sign = -1;
		len++;
	}
	else if (nptr[len] == '+')
		len++;
	return (len);
}

int	ft_atoi(const char *nptr)
{
	long long	nbr;
	size_t		i;
	int			sign;

	nbr = 0;
	sign = 1;
	i = init_atoi(nptr, &sign);
	while (nptr[i] && ft_isdigit((int)nptr[i]))
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
		return (0);
	return ((int)nbr * sign);
}
