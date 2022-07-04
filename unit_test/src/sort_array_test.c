/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   sort_array_test.c                               |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/04 11:40:15 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/04 11:40:43 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	sort_array_test(const int len, const int *input, const int *expected)
{
	size_t i;

	i = 0;
	sort_array(len, (int *)input);
	while (i < (size_t)len)
	{
		cr_assert(eq(int, input[i], expected[i]));
		i++;
	}
}
