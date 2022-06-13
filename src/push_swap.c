/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/22 11:47:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/13 23:01:14 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "push_swap.h"

/*Make sure size of arguments is at least 3 to make it sortable*/
bool	argc_checker(int argc)
{
	if (argc < 3)
		return (false);
	return (true);
}

/*Make sure arguments contain digits*/
bool	argv_checker(int len, char **argv)
{
	size_t i;

	i = 0;
	if (argv == NULL || **argv == '\0')
		return (false);
	while(i < (size_t)len)
	{
		if (ft_strbapi(argv[i], ft_isatoi) == false)
			return (false);
		i++;
	}
	return (true);
}

/*Initialize int array*/
int	*argvtoarray(int len, char **argv)
{
	size_t i;
	int *integer;

	integer = ft_calloc(len + 1, sizeof(int));
	if (integer == NULL || argv == NULL || **argv == '\0')
	{
		free(integer);
		ft_error();
		return (NULL);
	}
	i = 0;
	while (i < (size_t)len)
	{
		integer[i] = ft_atoi(argv[i]);
		if (integer[i] == 0 && ft_iszero(argv[i]) == false)
		{
			ft_error();
			return (NULL);
		}
		i++;
	}
	return (integer);
}

/*Integer shouldn't be sorted or contain duplicate integer values*/
/*bool	array_check(int len, int *integer)*/
/*{*/
	/*bool issorted;*/
	/*size_t i;*/

	/*if (!integer || len == 0)*/
	/*{*/
		/*ft_error();*/
		/*return (false);*/
	/*}*/
	/*i = 0;*/
	/*issorted = true;*/
	/*while (i < (size_t)len)*/
	/*{*/
		/*if (integer[i] > integer[i + 1] && i != (size_t)len - 1)*/
			/*issorted = false;*/
		/*if (ft_arrint(integer, integer[i], i))*/
		/*{*/
			/*ft_error();*/
			/*return (false);*/
		/*}*/
		/*i++;*/
	/*}*/
	/*if (issorted == false)*/
		/*return (true);*/
	/*ft_error();*/
	/*return (false);*/
/*}*/

/*handle conversion to int & INT_MINMAX before putting in to linked list*/
/*t_list	*init_stack(int len, const int *integer, t_list *stack_a)*/
/*{*/
	/*size_t	i;*/

	/*if (integer == NULL)*/
	/*{*/
		/*ft_error();*/
		/*return (NULL);*/
	/*}*/
	/*i = 0;*/
	/*while (i < (size_t)len)*/
	/*{*/

/* this line should be readded ft_lstadd_back(&stack_a, ft_lstnew(&integer[i])); */
		/*i++;*/
	/*}*/
	/*return (stack_a);*/
/*}*/

/*bool	sa(t_list *stack_a)*/
/*{*/
	/*if (ft_lstsize(stack_a) < 2)*/
		/*return (false);*/
	/*ft_swap(stack_a->content, (*stack_a).next->content);*/
	/*ft_putendl_fd("sa", 1);*/
	/*return (true);*/
/*}*/

/*bool	sb(t_list *stack_b)*/
/*{*/
	/*if (ft_lstsize(stack_b) < 2)*/
		/*return (false);*/
	/*ft_swap(stack_b->content, (*stack_b).next->content);*/
	/*ft_putendl_fd("sa", 1);*/
	/*return (true);*/
/*}*/

/*bool	ss(t_list *stack_a, t_list *stack_b)*/
/*{*/
	/*if (ft_lstsize(stack_a) < 2)*/
		/*return (false);*/
	/*ft_swap(stack_a->content, (*stack_a).next->content);*/
	/*if (ft_lstsize(stack_b) < 2)*/
		/*return (false);*/
	/*ft_swap(stack_b->content, (*stack_b).next->content);*/
	/*ft_putendl_fd("ss", 1);*/
	/*return (true);*/
/*}*/
