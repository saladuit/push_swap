/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   argv_checker.h                                  |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 17:37:37 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/08 17:39:23 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_CHECKER_H
# define	ARGV_CHECKER_H
# include	<stdbool.h>
# include "libft.h"

static bool	argv_checker_helper(const char *argument);
bool		argv_checker(const int len, const char **argv);

#endif
