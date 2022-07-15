/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/27 15:07:11 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/15 16:07:00 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leakscheck()
{
//	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
//	atexit(leakscheck);
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (push_swap(argc - 1, (const char **)&argv[1]) == false)
	{
		ft_error();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
