/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:03:19 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/22 18:12:47 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	ch;

	arr = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n)
	{
		if (*arr == ch)
			return (arr);
		n--;
		arr++;
	}
	return (NULL);
}
