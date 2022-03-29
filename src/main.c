/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/21 16:52:43 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/29 16:50:40 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list *stack_a;
	if(count_check(argc) == false || var_check(argc, &argv[1]) == false)
		return (0);
	stack_a = init_stack_a(argc, &argv[1]);
	ft_lstclear(&stack_a, (void *)&ft_lstdelone);
	return (0);
}
