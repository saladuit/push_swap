/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   array_check_test.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 16:13:47 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/24 15:30:03 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	array_check_test(const int len, const int *integer, const int expected)
{
	int submitted;

	/*can I add a macro to print the 2d ARray?*/
	submitted = array_check(len, integer);
	cr_assert(submitted == expected,
			"Called:\tarray_check_test()\nlen:\t\t%d\nexpected:\t%d \nsubmitted:\t%d\n",
			len,
			expected,
			submitted);
	return ;
}
