/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iszero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:05 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 23:12:52 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_iszero(const char *string)
{
	int i;

	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (string[i] != '0')	
			return (false);
		i++;
	}
	return (true);
}
