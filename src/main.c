/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/20 17:04:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 15:17:42 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_swap(int argc, const char **argv)
{
	int *integer;
	t_list *stack_a;

	if(argv_checker(argc - 1, &argv[1]) == false)
		return (false);
	stack_a = NULL;
	integer = NULL;
	integer = init_integer_array(argc - 1, &argv[1]);
	if (integer == NULL)
		return (false);
	/*if (array_check(argc - 1, integer))*/
		/*return (0);*/
	/*stack_a = init_stack(argc - 1, integer, stack_a);*/
	/*free(integer);*/
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (push_swap(argc, (const char **)argv) == false)
	{
		ft_error();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
