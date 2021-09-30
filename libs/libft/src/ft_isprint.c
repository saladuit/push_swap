/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:45:37 by saladin       #+#    #+#                 */
/*   Updated: 2021/07/26 16:29:39 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((unsigned int)c >= 32 && (unsigned int)c <= 126)
		return (1);
	else
		return (0);
}
