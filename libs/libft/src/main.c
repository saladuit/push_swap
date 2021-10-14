/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2021/10/13 14:05:27 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2021/10/14 13:27:39 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	main()
{
	t_list	*test;
	t_list	*test2;


	test = ft_lstnew("sldfj");
	test2 = ft_lstnew("dit is het tweede verhaal");
	ft_lstadd_front(&test, test2);
	return (0);
}
