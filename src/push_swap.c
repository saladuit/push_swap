/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:46:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 18:27:54 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	argv_checker_helper(const char *argument)
{
	bool isdigit;
	size_t i;

	i = 0; 
	isdigit = true;
	if(ft_isempty(argument[i]))
		return (false);
	while (argument[i])
	{
		if (i == 0)
		{
			if (ft_isatoi(argument[i]) == false)
				return (false);
			isdigit = ft_isdigit(argument[i]);
		}
		else
		{
			if (ft_isdigit(argument[i]) == false)
				return (false);
		}
		i++;
	}
	return (isdigit);
}

/*Make sure arguments contain digits*/
bool	argv_checker(const int len, const char **argv)
{

	size_t i;

	i = 0;
	while(i < (size_t)len)
	{
		if(argv_checker_helper(argv[i]) == false)
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


void	swap_top_list(t_list *stack)
{
	ft_swap(stack->content, stack->next->content);
}

void	push_top_node(t_list **dest, t_list **src)
{
	t_list *tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dest, *src);
	*src = tmp;
}

void	rotate_list(const size_t size, t_list **stack)
{
	size_t i;
	t_list *tmp;
	
	if (size < 2)
		return ;
	i = 0;
	tmp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	*stack = tmp;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	*stack = tmp;
}

void	rev_rotate_list(const size_t size, t_list **stack)
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
}

void	make_positive(const int len, int *integer)
{
	int *copy;
	size_t x;
	size_t y;

	x = 0;
	copy = ft_calloc(len, sizeof(int));
	if (copy == NULL)
		return ;
	ft_memcpy(copy, integer, len);
	ft_bubble_sort(len, copy);
	while (x < (size_t)len)
	{
		y = 0;
		while ( y < (size_t)len)
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
	free(copy);
	return ;
}

int	biggest_bit(int num)
{
	int max;

	max = 0;
	while ((num >> max) != 0)
		max++;
	return (max);
}

void	sort_radix(int len_a, t_list *stack_a)
{
	t_list *stack_b;
	int max_num; // the biggest number in a is stack_size - 1
	int max_bits; // how many bits for max_num 
	int len_b;
	int num;
	int i;
	int j;

	stack_b = NULL;
	len_b = 0;
	max_num = len_a - 1;
	max_bits = biggest_bit(max_num);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		while (j < len_a)
		{
			num = *(int *)stack_a->content;
			if (((num >> i)&1) == 1)
			{
				rotate_list(len_a, &stack_a);
				ft_putendl_fd("ra", 1);
				len_b++;
				len_a--;
			}
			else 
			{
				push_top_node(&stack_b, &stack_a);
				ft_putendl_fd("pb", 1);
				len_b++;
				len_a--;
			}
			j++;
		}
		while (len_b)
		{
			push_top_node(&stack_a, &stack_b);
			ft_putendl_fd("pa", 1);
			len_a++;
			len_b--;
		}
		i++;
	}
}

//void	sort_small_stack(len, stack_a)
//{
//	t_list *stack_b;
//	int top;
//	int mid;
//	int	bot; 
//
//	top = stack_a->content;
//	mid = stack_a->next->content;
//	bot = stack_a->next->next->content;
//	if (

static void	sort(const int len, t_list **stack_a)
{
	sort_radix(len, *stack_a);
	return ;
}

bool	push_swap(const int len, const char **argv)
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
	make_positive(len, integer);
	stack_a = NULL;
	stack_a = init_stack(len, integer);
	sort(len, &stack_a);
	free(integer);
	return (true);
}
