/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:07 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 17:54:19 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argv_checker_test(const int len, char **argv, const bool expected)
{
	bool submitted;

	submitted = argv_checker(len, argv);
	ft_put2d_fd(argv, 2, len);
	cr_assert(submitted == expected,
			"Called:\tcheck_argc_test()\nargc:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			len,
			argv,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
