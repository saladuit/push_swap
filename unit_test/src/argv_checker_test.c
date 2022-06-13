/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:07 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 18:52:17 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argv_checker_test(const int len, char **argv, const bool expected)
{
	bool submitted;

	submitted = argv_checker(len, argv);
	if (argv != NULL)
		ft_put2d_fd(argv, 1, len);
	cr_assert(submitted == expected,
			"Called:\tcheck_argv_test()\nlen:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			len,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
