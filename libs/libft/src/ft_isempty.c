/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_isempty.c                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/04 15:48:50 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/04 16:30:40 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_isempty(int c)
{
	if (c == '\0')
		return (true);
	return (false);
}