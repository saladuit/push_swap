/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   init_integer_array_tester.c                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/14 22:22:05 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/15 18:55:07 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void init_integer_array_tester(const int len, const char **argv, const int *expected)
{
	int *submitted;

	submitted = init_integer_array(len, argv);
	if (**argv == '\0')
		cr_assert_empty(submitted);
	else
		cr_assert_arr_eq(submitted, expected, len);
}
