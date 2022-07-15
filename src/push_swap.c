/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.c                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 14:46:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/15 18:27:20 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "init.h"
#include "argv_checker.h"
#include "sort.h"

static void	select_sorting_algorithm(const int len, t_list **stack_a)
{
	if (len == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (len <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (len <= 4)
	{
		sort_four(stack_a);
		return ;
	}
	if (len <= 5)
	{
		sort_five(stack_a);
		return ;
	}
	sort_radix(len, stack_a);
	return ;
}

static bool	clean_and_bool(void *m, bool state)
{
	free(m);
	system("leaks push_swap");
	return (state);
}

bool	push_swap(const int len, const char **argv)
{
	int		*integer;
	int		sort_state;
	t_list	*stack_a;

	if (argv_checker(len, argv) == false)
		return (false);
	integer = init_integer_array(len, argv);
	if (integer == NULL)
		return (false);
	sort_state = array_check(len, integer);
	if (sort_state == SORTED)
		return (clean_and_bool(integer, true));
	else if (sort_state == DOUBLE)
		return (clean_and_bool(integer, false));
	make_positive(len, integer);
	stack_a = init_stack(len, integer);
	select_sorting_algorithm(len, &stack_a);
	ft_free_list(&stack_a);
	return (clean_and_bool(integer, true));
}
