/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:25:41 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 14:44:28 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	unsigned char	ch;

	ch = (unsigned char)c;
	arr = (unsigned char *)b;
	while (len)
	{
		*arr = ch;
		arr++;
		len--;
	}
	return (b);
}
