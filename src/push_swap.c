/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:46:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 14:37:26 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	*parse_argv_to_array(const int len, const char **stack_a)
{
	if(argv_checker(len, stack_a) == false)
		return (NULL);
	return (init_integer_array(len, stack_a));
}

static void	select_sorting_algorithm(const int len, t_list **stack_a)
{
	if (len == 2)
	{
		sort_two(*stack_a);
		return ;
	}
	if (len <= 3)
	{
		sort_three(*stack_a);
		return ;
	}
	if (len <= 5)
	{
		sort_five(*stack_a);
		return ;
	}
	sort_radix(len, *stack_a);
	return ;
}

bool	push_swap(const int len, const char **argv)
{
	int		*integer;
	int		sort_state;
	t_list	*stack_a;

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
