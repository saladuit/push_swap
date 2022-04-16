/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                        :+:    :+:            */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/30 15:20:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/16 13:31:00 by saladuit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

bool	count_check(int argc);
bool	var_check(int len, char **argv);
bool	array_check(int len, int *integer);
int		*argvtoarray(int len, char **argv);
t_list	*init_stack(int len, int *integers, t_list *stack);

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
