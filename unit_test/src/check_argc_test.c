/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:14:47 by safoh             #+#    #+#             */
/*   Updated: 2022/06/11 21:30:00 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "push_swap.h"
#include <stdbool.h>
#include <fcntl.h>
#include "unit_push_swap.h"

#define formatBool(b) ((b) ? "true" : "false")

void	check_argc_test(const int argc, const bool expected, const char *error_output)
{
	bool submitted;

	if (fork() == 0)
	{
	submitted = count_check(argc);
	fflush(stderr);
	cr_assert(submitted == expected,
			"Called:\tcheck_argc_test()\nargc:\t\t%d\nexpected:\t%s \nsubmitted:\t%s\n",
			argc,
			formatBool(expected),
			formatBool(submitted));
	cr_assert_stderr_eq_str(error_output);
	exit(0);
	}
	waitpid()
	return ;
}
