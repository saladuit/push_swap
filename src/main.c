/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/28 17:31:18 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	/*if(count_check(argc) == false)*/
		/*return (0);*/
	if(var_check(&argv[1]) == false)
		return(0);
	push_swap(argc, argv);
	return (0);
}
