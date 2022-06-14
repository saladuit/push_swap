/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker_test.c                             |o_o || |                */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:07 by safoh             #+#    #+#             */
/*   Updated: 2022/06/14 20:44:36 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */


#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argv_checker_test(const int len, const char **argv, const bool expected)
{
	bool submitted;

	/*can I add a macro to print the 2d ARray?*/
	submitted = argv_checker(len, argv);
	cr_assert(submitted == expected,
			"Called:\tcheck_argv_test()\nlen:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			len,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
