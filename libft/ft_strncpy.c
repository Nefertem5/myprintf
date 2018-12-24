/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:56:06 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 17:44:02 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (len)
	{
		if (*src)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		len--;
		dst++;
	}
	return (ptr);
}
