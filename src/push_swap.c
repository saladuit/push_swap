/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/22 11:47:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 17:00:25 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

bool	count_check(int argc)
{
	if (argc == 2)
		ft_putstr_fd("error\n", 1);
	if (argc < 3)
		return (false);
	return (true);
}

bool	var_check(char **argv)
{
	size_t i;

	i = 0;
	if (argv == NULL)
		return (false);
	while(argv[i])
	{
		if (ft_strbapi(argv[i], ft_isdigit) == false)
		{
			ft_putstr_fd("error\n", 1);
			return (false);
		}
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
