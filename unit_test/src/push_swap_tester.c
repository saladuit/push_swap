/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/24 21:43:02 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/safoh/Documents/Projects_Codam/push_swap/include/push_swap.h"
#include "push_swap.h"
#include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"
#include "libft.h"
#include <string.h>

# define MAX_LEN 40

TestSuite(push_swap);

Test(push_swap, count_check)
{
	cr_assert(count_check(1) == false);
	cr_assert(count_check(2) == true);
}

/*check for:*/
/*- int min & max*/
/*- double numbers*/
/*- already sorted*/
/*- non-numeric parameters*/
/*- no parameters sould display nothing*/
/*- check "-"*/

Test(push_swap, var_check)
{
	char *string0 = NULL;
	char *string1 = "1";
	char *string2[2] = {"1", "2"};
	char *string3[2] = {"2", "1"};
	char *string4[2] = {"a", "2"};
	char *string5[2] = {"1", "a"};
	char *string6[2] = {"1", "1a"};
	char *string7[2] = {"1", "-"};
	char *string8[3] = {"1", "2", "1"};

	cr_assert(var_check(&string0) == false);
	cr_assert(var_check(&string1) == false);
	cr_assert(var_check(string2) == false);
	cr_assert(var_check(string3) == false);
	cr_assert(var_check(string4) == false);
	cr_assert(var_check(string5) == false);
	cr_assert(var_check(string6) == false);
	cr_assert(var_check(string7) == false);
	cr_assert(var_check(string8) == false);
	var = ft_split("1,2,3", ',');
	cr_assert(var_check("") == false);
	free_str_arr(var);
	while (arr[i])
		free(arr[i])
}
