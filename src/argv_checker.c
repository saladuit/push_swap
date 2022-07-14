/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   argv_checker.c                                  |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/08 17:36:49 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:33:10 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "argv_checker.h"

static bool	argv_checker_helper(const char *argument)
{
	bool	isdigit;
	size_t	i;

	i = 0;
	isdigit = true;
	if (ft_isempty(argument[i]))
		return (false);
	while (argument[i])
	{
		if (i == 0)
		{
			if (ft_isatoi(argument[i]) == false)
				return (false);
			isdigit = ft_isdigit(argument[i]);
		}
		else if (ft_isdigit(argument[i]) == false)
			return (false);
		i++;
	}
	if (i == 1 && isdigit == false)
		return (false);
	return (true);
}

/*Make sure arguments contain valid integers*/
bool	argv_checker(const int len, const char **argv)
{
	size_t	i;

	i = 0;
	while (i < (size_t)len)
	{
		if (argv_checker_helper(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
