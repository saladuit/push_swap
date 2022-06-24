/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/20 17:04:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/24 17:09:33 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	*parse_argv_to_array(int argc, const char **argv)
{
	if(argv_checker(argc - 1, &argv[1]) == false)
		return (NULL);
	return (init_integer_array(argc - 1, &argv[1]));
}

bool	push_swap(int argc, const char **argv)
{
	int *integer;
	int sort_state;
	t_list *stack_a;

	integer = parse_argv_to_array(argc, argv);
	if (integer == NULL)
		return (false);
	sort_state = array_check(argc - 1, integer);
	if (sort_state == SORTED)
		return (true);
	else if (sort_state == DOUBLE)
		return (false);
	if (array_check(argc - 1, integer) == false)
		return (false);
	stack_a = NULL;
	/*stack_a = init_stack(argc - 1, integer, stack_a);*/
	free(integer);
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
