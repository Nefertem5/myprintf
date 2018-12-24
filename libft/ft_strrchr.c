/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:35:26 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/23 15:59:47 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*start;
	char		ch;

	start = s;
	ch = (char)c;
	while (*s)
		s++;
	while (s != start)
	{
		if (ch == *s)
			return ((char *)s);
		s--;
	}
	if (*start == ch)
		return ((char *)s);
	return (NULL);
}
