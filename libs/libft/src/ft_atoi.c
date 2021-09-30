/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 18:50:33 by saladin       #+#    #+#                 */
/*   Updated: 2021/07/26 17:03:49 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	bool	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

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
		if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)nbr * sign);
}
