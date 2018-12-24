/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:46:09 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/28 16:32:16 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*newlst;
	t_list	*current;
	t_list	*oldlst;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	if (!newlst)
		return (NULL);
	oldlst = newlst;
	current = lst->next;
	while (current)
	{
		next = current->next;
		newlst->next = f(current);
		if (!newlst->next)
			return (NULL);
		newlst = newlst->next;
		current = next;
	}
	return (oldlst);
}
