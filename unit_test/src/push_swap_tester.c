/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/23 22:30:54 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"
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
	char buffer[MAX_LEN+1] = {0};
	int out_pipe[2];
	int saved_stdout;
	char string[1] = "a";

	saved_stdout = dup(STDOUT_FILENO);  /* save stdout for display later */
	if( pipe(out_pipe) != 0 )
	{          /* make a pipe */
		exit(1);
	}

	dup2(out_pipe[1], STDOUT_FILENO);   /* redirect stdout to the pipe */
	close(out_pipe[1]);

	/* anything sent to printf should now go down the pipe */
	var_check(string);
	fflush(stdout);
	read(out_pipe[0], buffer, MAX_LEN); /* read from pipe into buffer */
	dup2(saved_stdout, STDOUT_FILENO);  /* reconnect stdout for testing */
	cr_assert(var_check(string) == false);
	cr_assert(printf("read: %s\n", buffer) == "error\n");
}
