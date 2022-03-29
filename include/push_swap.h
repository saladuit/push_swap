/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/09/30 15:20:23 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/29 17:17:33 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"

char	*push_swap(int argc, char **list);
bool	count_check(int argc);
bool	var_check(int argc, char **argv);
t_list *init_stack_a(int argc, char **argv);
#endif
