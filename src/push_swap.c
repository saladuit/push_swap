/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saladuit <safoh@student.codam.nl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:11:50 by saladuit          #+#    #+#             */
/*   Updated: 2022/06/25 02:05:13 by saladuit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Make sure arguments contain digits*/
bool	argv_checker(const int len, const char **argv)
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

/*We want to check whether the values inside are correct*/
int	*init_integer_array(const int len, const char **argv)
{
	size_t i;
	int *integer;

	if (argv == NULL || **argv == '\0')
		return (NULL);
	integer = ft_calloc(len + 1, sizeof(int));
	if (integer == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)len)
	{
		integer[i] = ft_atoi(argv[i]);
		if (integer[i] == 0 && ft_iszero(argv[i]) == false)
		{
			free(integer);
			return (NULL);
		}
		i++;
	}
	return (integer);
}

int	*parse_argv_to_array(int len, const char **stack_a)
{
	if(argv_checker(len, stack_a) == false)
		return (NULL);
	return (init_integer_array(len, stack_a));
}

/*Integer shouldn't be sorted or contain duplicate integer values*/
int	array_check(const int len, const int *integer)
{
	size_t i;

	i = 0;
	while (i < (size_t)len)
	{
		if (integer[i] > integer[i + 1] && i != (size_t)len - 1)
			return (NOT_SORTED);
		if (ft_arrint(integer, integer[i], i))
			return (DOUBLE);
		i++;
	}
	return (SORTED);
}


bool	push_swap(int len, const char **argv)
{
	int *integer;
	int sort_state;
//	t_list *stack_a;

	integer = parse_argv_to_array(len, &argv[1]);
	if (integer == NULL)
		return (false);
	sort_state = array_check(len, integer);
	if (sort_state == SORTED)
		return (true);
	else if (sort_state == DOUBLE)
		return (false);
	if (array_check(len, integer) == false)
		return (false);
//	stack_a = NULL;
	/*stack_a = init_stack(len - 1, integer, stack_a);*/
	free(integer);
	return (true);
}

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
