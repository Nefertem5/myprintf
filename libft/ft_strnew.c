/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:09:32 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/30 14:00:22 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
