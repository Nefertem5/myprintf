/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:04:02 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/29 18:37:58 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	if (needle == haystack)
		return ((char *)haystack);
	i = 0;
	while (*haystack)
	{
		while (haystack[i] == needle[i] && haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
