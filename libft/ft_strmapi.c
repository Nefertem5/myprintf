/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:01:06 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/30 00:00:04 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*start;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	start = new;
	index = 0;
	while (s[index] && f)
	{
		new[index] = f(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (start);
}
