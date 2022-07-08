/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:46:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/08 18:17:48 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>


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
	max_bits = bit_count(max_num);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		while (j < len_a)
		{
			num = *(int *)stack_a->content;
			if (((num >> i)&1) == 1)
			{
				ft_rotate_list(&stack_a, stack_a);
				ft_putendl_fd("ra", STDOUT_FILENO);
			}
			else 
			{
				ft_push_node(&stack_b, &stack_a);
				ft_putendl_fd("pb", STDOUT_FILENO);
			}
			j++;
		}
		len_b = ft_lstsize(stack_b);
		while (len_b)
		{
			ft_push_node(&stack_a, &stack_b);
			ft_putendl_fd("pa", STDOUT_FILENO);
			len_b--;
		}
		i++;
	}
}

static void	sort_two(t_list *stack_a)
{
		swap_a(stack_a);
}

static	int	*parse_argv_to_array(const int len, const char **stack_a)
{
	if(argv_checker(len, stack_a) == false)
		return (NULL);
	return (init_integer_array(len, stack_a));
}

static void	select_sorting_algorithm(const int len, t_list **stack_a)
{
	if (len == 2)
		sort_two(*stack_a);
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
	select_sorting_algorithm(len, &stack_a);
	free(integer);
	return (true);
}
