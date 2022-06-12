/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:14:47 by safoh             #+#    #+#             */
/*   Updated: 2022/06/12 21:21:55 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argc_check_tester(const int argc, const bool expected)
{
	bool submitted;

	submitted = argc_check(argc);
	cr_assert(submitted == expected,
			"Called:\tcheck_argc_test()\nargc:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			argc,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
