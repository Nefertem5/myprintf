/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:21:09 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 14:49:09 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		*ptr_dst = *ptr_src;
		n--;
		ptr_dst++;
		ptr_src++;
	}
	return (dst);
}
