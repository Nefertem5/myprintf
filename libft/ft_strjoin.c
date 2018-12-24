/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:58:07 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/30 13:56:48 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*start_joined;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = ft_strnew(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	start_joined = joined;
	while (*s1)
		*joined++ = *s1++;
	ft_strcat(joined, s2);
	return (start_joined);
}
