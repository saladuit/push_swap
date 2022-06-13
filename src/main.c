/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:21:24 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 16:09:54 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_swap(int argc, char **argv)
{
	/*int *integer;*/
	/*t_list *stack_a;*/

	if(count_check(argc) == false || var_check(argc - 1, &argv[1]) == false)
		return (-1);
	/*stack_a = NULL;*/
	/*integer = NULL;*/
	/*integer = argvtoarray(argc - 1, &argv[1]);*/
	/*if (array_check(argc - 1, integer))*/
		/*return (0);*/
	/*stack_a = init_stack(argc - 1, integer, stack_a);*/
	/*free(integer);*/
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (EXIT_SUCCES);
	if (push_swap(argc, argv) == false)
	{
		ft_error();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCES);
}
