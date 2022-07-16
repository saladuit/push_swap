/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   init.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 17:57:18 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/16 15:50:20 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	helper(int *integer, int *copy, int len)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < (size_t)len)
	{
		y = 0;
		while (y < (size_t)len)
		{
			if (integer[x] == copy[y])
			{
				integer[x] = y;
				break ;
			}
			y++;
		}
		x++;
	}
}

// Prepare array for radix sort
void	make_positive(const int len, int *integer)
{
	int	*copy;

	copy = ft_calloc(len, sizeof(int));
	if (copy == NULL)
		return ;
	ft_memcpy(copy, integer, len);
	ft_bubble_sort(len, copy);
	helper(integer, copy, len);
	free(copy);
	return ;
}

/*We want to check whether the values inside are correct*/
int	*init_integer_array(const int len, const char **argv)
{
	size_t	i;
	int		*integer;

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
	size_t	i;

	i = 0;
	while (i < (size_t)len)
	{
		if (ft_arrint(integer, integer[i], i))
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
	t_list	*stack;
	t_list	*tmp;
	size_t	i;

	i = 0;
	stack = NULL;
	while (i < (size_t)len)
	{
		tmp = ft_lstnew((void *)&integer[i]);
		if (!tmp)
		{
			ft_free_list(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}
