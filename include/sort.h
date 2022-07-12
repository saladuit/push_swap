/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort.h                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 18:17:17 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/12 16:44:28 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "libft.h"

void	sort_radix(int len_a, t_list *stack_a);
void	sort_two(t_list *stack_a);
void	sort_five(t_list **stack_a);
void	sort_three(t_list **stack_a);

#endif
