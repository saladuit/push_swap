/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/22 11:47:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/29 17:16:25 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/push_swap.h"

bool	count_check(int argc)
{
	if (argc == 2)
		ft_putstr_fd("error\n", 1);
	if (argc < 3)
		return (false);
	return (true);
}

bool	var_check(int len, char **argv)
{
	size_t i;

	i = 0;
	if (argv == NULL)
		return (false);
	while(i < (size_t)len)
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

t_list *init_stack_a(int argc, char **argv)
{
	t_list	*stack_a;
	int integer;
	size_t	i;
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)argc)
	{
		integer = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(&integer));
		i++;
	}
	return (stack_a);
}
