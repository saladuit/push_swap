/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   actions.h                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/07 21:24:55 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 21:53:51 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_AB		"ss"
# include "libft.h"
void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);

#endif
