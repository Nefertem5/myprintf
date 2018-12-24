/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:24:56 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/28 15:33:16 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;
	t_list	*current;

	if (lst && f)
	{
		next = lst->next;
		current = lst;
		while (current)
		{
			next = current->next;
			f(current);
			current = next;
		}
	}
}
