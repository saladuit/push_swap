/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/15 18:40:38 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/17 16:38:21 by safoh            ###   ########.fr       */
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
