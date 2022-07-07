/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_top_node_test.c                            |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/01 16:09:12 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 21:59:41 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

//static void	check_stack(size_t size, t_list *stack, const int *expected)
//{
//	int number;
//	size_t i = 0;
//
//	while(i < (size_t)size)
//	{
//		number = *(int *)stack->content;
//		cr_assert(eq(int, number, expected[i]));
//		stack = stack->next;
//		i++;
//	}
//	return ;
//}
//
//void	push_top_node_test(const size_t size_a, const size_t size_b, \
//		const int *input_a, const int *input_b, \
//		const int *expected_a, const int *expected_b)
//{
//	t_list *stack_a = NULL;
//	t_list *stack_b = NULL;
//
//	stack_a = init_stack(size_a, input_a);
//	stack_b = init_stack(size_b, input_b);
//	push_top_node(&stack_b, &stack_a);
//	if (size_a != 0)
//	{
//		check_stack(size_a - 1, stack_a, expected_a);
//		check_stack(size_b + 1, stack_b, expected_b);
//	}
//	else
//	{
//		check_stack(size_a, stack_a, expected_a);
//		check_stack(size_b, stack_b, expected_b);
//	}
//	return ;
//}
