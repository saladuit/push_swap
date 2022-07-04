/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:46:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/04 09:54:30 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

/*Make sure arguments contain digits*/
bool	argv_checker(const int len, const char **argv)
{
	size_t i;

	i = 0;
	while(i < (size_t)len)
	{
		if (ft_strbapi(argv[i], ft_isatoi) == false || *argv[i] == '\0')
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

	if (**argv == '\0')
		return (NULL);
	integer = ft_calloc(len + 1, sizeof(int));
	if (integer == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)len)
	{
		integer[i] = ft_atoi(argv[i]);
		if ((integer[i] == 0 && ft_iszero(argv[i]) == false) || *argv[i] == '\0')
		{
			free(integer);
			integer = NULL;
			return (NULL);
		}
		i++;
	}
	return (integer);
}

int	*parse_argv_to_array(const int len, const char **stack_a)
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


void	swap_top_list(t_list *stack, char *action)
{
	ft_swap(stack->content, stack->next->content);
	ft_putendl_fd(action, 1);
}

void	push_top_node(t_list **dest, t_list **src, char *action)
{
	t_list *tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	ft_lstadd_front(dest, *src);
	*src = (*tmp).next;
	ft_putendl_fd(action, 1);
}

void	rotate_list(const size_t size, t_list **stack, char *action)
{
	t_list *tmp;
	if (size < 2)
		return ;
	tmp = *stack;
	ft_lstadd_back(stack, *stack);
	*stack = (*tmp).next;
	ft_putendl_fd(action, 1);
}


void	rev_rotate_list(const size_t size, t_list **stack, char *action)
{
	size_t i;
	t_list *tmp;

	if (size < 2)
		return ;
	i = 0;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	tmp = *stack;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	*stack = tmp;
	ft_putendl_fd(action, 1);
}

bool	push_swap(int len, const char **argv)
{
	int *integer;
	int sort_state;
	t_list *stack_a;

	integer = parse_argv_to_array(len, argv);
	if (integer == NULL)
		return (false);
	sort_state = array_check(len, integer);
	if (sort_state == SORTED)
		return (true);
	else if (sort_state == DOUBLE)
		return (false);
	stack_a = NULL;
	stack_a = init_stack(len, integer);
	free(integer);
	return (true);
}
