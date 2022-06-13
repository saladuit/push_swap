/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:14:47 by safoh             #+#    #+#             */
/*   Updated: 2022/06/13 17:53:48 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

#define formatBool(b) ((b) ? "true" : "false")

void	argc_checker_test(const int argc, const bool expected)
{
	bool submitted;

	submitted = argc_checker(argc);
	cr_assert(submitted == expected,
			"Called:\tcheck_argc_test()\nargc:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			argc,
			formatBool(expected),
			formatBool(submitted));
	return ;
}
