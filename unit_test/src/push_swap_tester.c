/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/25 12:18:11 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/redirect.h>
#include <criterion/internal/test.h>
#include <criterion/new/assert.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "/Users/safoh/Documents/Projects_Codam/push_swap/include/push_swap.h"
#include "/Users/safoh/Documents/Projects_Codam/push_swap/libs/libft/include/libft.h"
#include <string.h>

# define MAX_LEN 40

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

void assert_empty_stdout()
{
	FILE	*f_stdout;
	f_stdout = cr_get_redirected_stdout();
	cr_expect(f_stdout == NULL);

}

/* ************************************************************************** */

TestSuite(program_call, .init=redirect_all_stdout);

Test(program_call, one_arg, .fini=assert_empty_stdout)
{
	cr_expect(count_check(1) == false);
}

Test(program_call, two_arg)
{
	cr_expect(count_check(2) == false);
	cr_expect_stdout_eq_str("error\n");
}

Test(count, more_than_two_arg, .fini=assert_empty_stdout)
{
	cr_expect(count_check(3) == true);
}

/* ************************************************************************** */
/*check for:*/
/*- int min & max*/
/*- double numbers*/
/*- already sorted*/
/*- non-numeric parameters*/
/*- no parameters sould display nothing*/
/*- check "-"*/
TestSuite(var, .init=redirect_all_stdout);

Test(var, NULL_pointer, .fini=assert_empty_stdout)
{
	char *string = NULL;
	cr_expect(var_check(&string) == false);
}
	/*char *string1 = "1";*/
	/*char *string2[2] = {"1", "2"};*/
	/*char *string3[2] = {"2", "1"};*/
	/*char *string4[2] = {"a", "2"};*/
	/*char *string5[2] = {"1", "a"};*/
	/*char *string6[2] = {"1", "1a"};*/
	/*char *string7[2] = {"1", "-"};*/
	/*char *string8[3] = {"1", "2", "1"};*/
	/*char **string9;*/
/*cr_assert_stdout_eq_str("foobar\n"); // assert that stdout contains the expected string*/
/*cr_assert_stderr_eq_str("-"); // assert that stderr ONLY contains our dummy print. (so nothing was printed)*/
	/*cr_assert(var_check(&string0) == false);*/
	/*cr_assert(var_check(&string1) == false);*/
	/*cr_assert(var_check(string2) == false);*/
	/*cr_assert(var_check(string3) == false);*/
	/*cr_assert(var_check(string4) == false);*/
	/*cr_assert(var_check(string5) == false);*/
	/*cr_assert(var_check(string6) == false);*/
	/*cr_assert(var_check(string7) == false);*/
	/*cr_assert(var_check(string8) == false);*/
	/*string9 = ft_split("1,2,3", ',');*/
	/*cr_assert(var_check("") == false);*/
	/*free_str_arr(var);*/
	/*while (arr[i])*/
		/*free(arr[i])*/
/*}*/
