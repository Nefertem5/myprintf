/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:39:55 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/28 15:03:15 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (alst && del)
	{
		current = *alst;
		next = current->next;
		while (current)
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = NULL;
			current = next;
		}
		*alst = NULL;
	}
}
