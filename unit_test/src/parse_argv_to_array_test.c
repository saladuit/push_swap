/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv_to_array_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saladuit <safoh@student.codam.nl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:57:32 by saladuit          #+#    #+#             */
/*   Updated: 2022/06/25 02:00:46 by saladuit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	parse_argv_to_array_test(const int len, const char **argv, const int *expected)
{
	int *submitted;

	submitted = parse_argv_to_array(len, argv);
	if (expected == NULL)
		cr_assert(zero(ptr, submitted));
	else
		cr_assert_arr_eq(submitted, expected, len);
}
