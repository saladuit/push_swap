/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/11 14:52:35 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>
#include <stdio.h>

bool	setup_argvtoarray(char **argv)
{
	int	len;
	int i;
	int	*integer = NULL;
	long	*expected = NULL;

	len = 0;
	i = 0;
	if (argv)
		while (argv[len])
			len++;
	expected = calloc(len + 1, sizeof(long));
	integer = argvtoarray(len, argv);
	if (!argv && integer)
	{
		free(expected);
		free(integer);
		return (false);
	}
	while (i < len)
	{

		expected[i] = atol(argv[i]);
		if (expected[i] != integer[i])
			return (false);
		i++;
	}
	free(expected);
	free(integer);
	return(true);
}

int	main(void)
{
	char	*string[] = {"-+-2147483648", NULL};

	setup_argvtoarray(string);

}
/*int	main(int argc, char **argv)*/
/*{*/
	/*t_list *stack_a;*/
	/*int *integer;*/
	/*if(count_check(argc) == false || var_check(argc - 1, &argv[1]) == false)*/
		/*return (0);*/
	/*stack_a = NULL;*/
	/*integer = NULL;*/
	/*integer = argvtoarray(argc - 1, &argv[1]);*/
	/*if (array_check(argc - 1, integer))*/
		/*return (0);*/
	/*stack_a = init_stack_a(argc - 1, integer, stack_a);*/
	/*free(integer);*/
	/*return (0);*/
/*}*/

