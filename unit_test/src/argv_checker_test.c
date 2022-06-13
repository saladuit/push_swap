/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:07 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 22:44:37 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argv_checker_test(const int len, char **argv, const bool expected)
{
	bool submitted;
	size_t i;

	i = 0;
	/*can I add a macro to print the 2d ARray?*/
	submitted = argv_checker(len, argv);
	cr_assert(submitted == expected,
			"Called:\tcheck_argv_test()\nlen:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			len,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
