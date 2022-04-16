/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                             :+:    :+:            */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/04/16 13:40:19 by saladuit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>
#include <stdio.h>

bool	check_sa(int *expected)
{
	t_list	*stack_a = NULL;
	int *checker = NULL;
	int len = 0;
	int i = 0;
	int number = 0;

	if (expected)
		while (expected[len])
			len++;
	checker = ft_calloc(len + 1, sizeof(int));
	if (!checker)
		return (false);
	while (expected[i])
	{
		checker[i] = expected[i];
		i++;	
	}
	i = 0;
	stack_a = init_stack(len, expected, stack_a);
	if (stack_a == NULL)
		if (expected)
		return (false);
	ft_swap(&checker[0], &checker[1]);
	sa(stack_a);
	while(i < len)
	{
		number = *(int *)stack_a->content;
		if(number != checker[i])
			return (false);
		stack_a = stack_a->next;
		i++;
	}
	ft_lstclear(&stack_a, NULL);
	return (true);
}

int	main(void)
{
	int	expected[] = {1, 2, '\0'};

	check_sa(expected);
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
	/*stack_a = init_stack(argc - 1, integer, stack_a);*/
	/*free(integer);*/
	/*return (0);*/
/*}*/

