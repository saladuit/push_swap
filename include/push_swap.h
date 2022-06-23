/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:17:07 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 15:17:09 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

bool	argv_checker(const int len, const char **argv);
int		*init_integer_array(const int len, const char **argv);

bool	array_check(int len, int *integer);
t_list	*init_stack(int len, const int *integers, t_list *stack);

//actions
bool	sa(t_list *stack_a);
bool	sb(t_list *stack_b);
bool	ss(t_list *stack_a, t_list *stack_b);
bool	pa(t_list *stack_a);
bool	pb(t_list *stack_b);
bool	ra(t_list *stack_a);
bool	rb(t_list *stack_b);
bool	rr(t_list *stack_a, t_list *stack_b);
bool	rra(t_list *stack_a);
bool	rrb(t_list *stack_b);
bool	rrr(t_list *stack_a, t_list *stack_b);
#endif
