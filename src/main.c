/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/02 16:03:15 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list *stack_a;
	int *integer;
	if(count_check(argc) == false || var_check(argc - 1, &argv[1]) == false)
		return (0);
	stack_a = NULL;
	integer = NULL;
	integer = argvtoarray(argc - 1, &argv[1], integer);
	if (array_check(argc - 1, integer))
		return (0);
	stack_a = init_stack_a(argc - 1, integer, stack_a);
	free(integer);
	return (0);
}

