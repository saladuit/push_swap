/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   redirect_all_stdout.c                           |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:46:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/25 18:56:12 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}
