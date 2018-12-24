/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:35:14 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/30 14:08:45 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*pos;
	char		*tmp;

	if (!*needle || needle == haystack)
		return ((char *)haystack);
	i = 0;
	pos = (char *)haystack + len;
	while (haystack != pos && *haystack)
	{
		tmp = (char *)haystack;
		while (*haystack == needle[i] && haystack != pos && *haystack)
		{
			i++;
			haystack++;
		}
		if (!needle[i])
			return (tmp);
		haystack = tmp;
		i = 0;
		haystack++;
	}
	return (NULL);
}
