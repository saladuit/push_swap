/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:17:07 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/25 01:05:03 by saladuit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

enum arrayCheck {
	DOUBLE = -1,
	SORTED = 0,
	NOT_SORTED = 1,
};

// Parsing Functions
bool	argv_checker(const int len, const char **argv);
int		*init_integer_array(const int len, const char **argv);


int	array_check(const int len, const int *integer);
t_list	*init_stack(int len, const int *integers, t_list *stack);

// Main logic functions
int	*parse_argv_to_array(int len, const char **argv);
bool	push_swap(int argc, const char **argv);

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
