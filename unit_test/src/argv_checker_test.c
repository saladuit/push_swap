/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   argv_checker_test.c                             |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/20 17:04:40 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/20 17:11:41 by safoh        \___)=(___/                 */
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
