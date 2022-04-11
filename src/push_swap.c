/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/22 11:47:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/05 14:54:42 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/push_swap.h"

void	ft_error(void)
{
		ft_putendl_fd("Error", 2);

}

/*Make sure size of arguments is at least 3 to make it sortable*/
bool	count_check(int argc)
{
	if (argc == 2)
		ft_error();
	if (argc < 3)
		return (false);
	return (true);
}

/*Make sure arguments contain digits*/
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
			ft_error();
			return (false);
		}
		i++;
	}
	return (true);
}

/*Initialize int array*/
int	*argvtoarray(int len, char **argv, int *integer)
{
	size_t i;

	integer = ft_calloc(len + 1, sizeof(int));
	if (integer == NULL || argv == NULL || len == 0)
	{
		ft_error();
		return (NULL);
	}
	i = 0;
	while (i < (size_t)len)
	{
		integer[i] = ft_atoi(argv[i]);
		if (ft_strncmp(ft_itoa(integer[i]), argv[i], ft_strlen(argv[i])))
		{
			ft_error();
			return (NULL);
		}
		i++;
	}
	return (integer);
}

/*Integer shouldn't be sorted or contain duplicate integer values*/
bool	array_check(int len, int *integer)
{
	bool issorted;
	size_t i;

	if (!integer || len == 0)
	{
		ft_error();
		return (false);
	}
	i = 0;
	issorted = true;
	while (i < (size_t)len)
	{
		if (integer[i] > integer[i + 1] && i != (size_t)len - 1)
			issorted = false;
		if (ft_arrint(integer, integer[i], i))
		{
			ft_error();
			return (false);
		}
		i++;
	}
	if (issorted == false)
		return (true);
	ft_error();
	return (false);
}

/*handle conversion to int & INT_MINMAX before putting in to linked list*/
t_list	*init_stack_a(int len,int *integer, t_list *stack_a)
{
	size_t	i;

	if (integer == NULL)
	{
		ft_error();
		return (NULL);
	}
	i = 0;
	while (i < (size_t)len)
	{
		ft_lstadd_back(&stack_a, ft_lstnew((void *)&integer[i]));
		i++;
	}
	return (stack_a);
}
