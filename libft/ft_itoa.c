/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:01:56 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 22:21:17 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_num_len(long long int n, unsigned int *len)
{
	if (n == 0)
		*len = 1;
	if (n < 0)
	{
		*len += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	int				sign;
	long long int	ln;

	ln = (long long int)n;
	sign = ln >= 0 ? 1 : -1;
	len = 0;
	ft_num_len(ln, &len);
	ln *= sign;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign < 0)
		str[0] = '-';
	while (ln && len - 1)
	{
		str[len - 1] = (ln % 10) + '0';
		ln /= 10;
		len--;
	}
	if (sign > 0)
		str[0] = (ln % 10) + '0';
	return (str);
}
