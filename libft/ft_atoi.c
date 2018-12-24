/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:52:04 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 20:43:03 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		if ((*str - '0') * 10 > 9223372036854775807 - result)
			return (sign == -1 ? 0 : -1);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * (int)result);
}
