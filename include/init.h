/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   init.h                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 17:49:30 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/08 18:00:49 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INIT_H
# define	INIT_H
# include "libft.h"

int	array_check(const int len, const int *integer);
int	*init_integer_array(const int len, const char **argv);
t_list	*init_stack(const int len, const int *integer)

#endif
