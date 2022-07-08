/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   init_integer_array.c                            |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 17:57:18 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/08 18:00:36 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/*We want to check whether the values inside are correct*/
int	*init_integer_array(const int len, const char **argv)
{
	size_t i;
	int *integer;

	integer = ft_calloc(len, sizeof(int));
	if (integer == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)len)
	{
		integer[i] = ft_atoi(argv[i]);
		if ((integer[i] == 0 && ft_iszero(argv[i]) == false))
		{
			integer = ft_memdel((void *)integer);
			return (NULL);
		}
		i++;
	}
	return (integer);
}

/*Integer shouldn't be sorted or contain duplicate integer values*/
int	array_check(const int len, const int *integer)
{
	size_t i;

	i = 0;
	while (i < (size_t)len)
	{
		if (ft_arrint(integer, integer[i], i)) //should be placed in init_integer_array
			return (DOUBLE);
		i++;
	}
	i = 0;
	while (i < (size_t)len - 1)
	{
		if (integer[i] > integer[i + 1])
			return (NOT_SORTED);
		i++;
	}
	return (SORTED);
}

// handle conversion to int & INT_MINMAX before putting in to linked list
t_list	*init_stack(const int len, const int *integer)
{
	t_list *stack;
	size_t	i;

	i = 0;
	stack = NULL;
	while (i < (size_t)len)
	{
		ft_lstadd_back(&stack, ft_lstnew((void *)&integer[i])); 
		i++;
	}
	return (stack);
}
