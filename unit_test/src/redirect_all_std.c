/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   redirect_all_stdout.c                              :+:      :+:    :+:   */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:46:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/11 19:14:03 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}
