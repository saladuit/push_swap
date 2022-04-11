/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/30 15:20:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/11 18:18:44 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"

bool	count_check(int argc);
bool	var_check(int len, char **argv);
bool	array_check(int len, int *integer);
int		*argvtoarray(int len, char **argv);
t_list	*init_stack_a(int len, int *integers, t_list *stack_a);

//actions
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list *stack_a);
void	pb(t_list *stack_b);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list *stack_a, t_list *stack_b);
#endif
