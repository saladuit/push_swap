/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_sgdnumlen.c                                  |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/06/23 15:11:59 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_sgdnumlen(long long num)
{
	if (num < 0)
		return (ft_numlen(num) + 1);
	return (ft_numlen(num));
}
