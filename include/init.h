/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                          |o_o || |                */
/*                                                    +:+ +:+         +:+     */
/*   By: saladuit <safoh@student.codam.nl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:10:45 by saladuit          #+#    #+#             */
/*   Updated: 2022/07/14 20:23:01 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "libft.h"

enum e_arrayCheck {
	DOUBLE,
	SORTED,
	NOT_SORTED
};

int		array_check(const int len, const int *integer);
int		*init_integer_array(const int len, const char **argv);
t_list	*init_stack(const int len, const int *integer);
void	make_positive(const int len, int *integer);

#endif
