/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/22 11:47:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/24 20:34:16 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"

bool	count_check(int argc)
{
	if (argc < 2)
		return (false);
	return (true);
}

bool	var_check(char **argv)
{
	size_t i;

	i = 0;
	while(argv[i])
	{
		if (!ft_strbapi(argv[i], ft_isdigit))
			return (false);
		i++;
	}
	return (true);
}

char	*push_swap(int argc, char **list)
{
	list = NULL;
	argc++;
	return (*list);
}
