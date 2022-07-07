/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:17:07 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/07 21:51:33 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "actions.h"
# include "libft.h"

enum arrayCheck {
	DOUBLE = -1,
	SORTED = 0,
	NOT_SORTED = 1,
};

// Parsing Functions
bool	argv_checker(const int len, const char **argv);
int		*init_integer_array(const int len, const char **argv);
void	make_positive(const int len, int *integer);
void	sort_array(const int len, int *integer);


int	array_check(const int len, const int *integer);
t_list	*init_stack(int len, const int *integers);

// Main logic functions
int	*parse_argv_to_array(int len, const char **argv);
bool	push_swap(int argc, const char **argv);

//actions
#endif
