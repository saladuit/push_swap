/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   actions.h                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:04:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 15:38:17 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_AB		"ss"

# define ROTATE_A		"ra"
# define ROTATE_B		"rb"
# define ROTATE_AB		"rr"

# define REV_ROTATE_A	"rra"
# define REV_ROTATE_B	"rrb"
# define REV_ROTATE_AB	"rrr"

# define PUSH_A			"pa"
# define PUSH_B			"pb"

# include "libft.h"

void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);

void	rotate_a(t_list *stack_a);
void	rotate_b(t_list *stack_b);
void	rotate_ab(t_list *stack_a, t_list *stack_b);

void	rev_rotate_a(t_list *stack_a);
void	rev_rotate_b(t_list *stack_b);
void	rev_rotate_ab(t_list *stack_a, t_list *stack_b);

void	push_b(t_list *stack_a, t_list *stack_b);
void	push_a(t_list *stack_a, t_list *stack_b);

#endif
