/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   swap.h                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:04:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/11 15:29:16 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
#define SWAP_A		"sa"
#define SWAP_B		"sb"
#define SWAP_AB		"ss"

# include "libft.h"

void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);

#endif
