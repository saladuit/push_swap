/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/23 20:14:27 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	if(!input_check(argc, argv))
		return (0);
	push_swap(argc, argv);
	return (0);
}
