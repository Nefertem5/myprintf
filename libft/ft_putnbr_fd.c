/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreutel <ttreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:02:35 by ttreutel          #+#    #+#             */
/*   Updated: 2018/11/30 13:26:37 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	ln;

	ln = (long long int)n;
	if (ln == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (ln == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return ;
	}
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putchar_fd(ln % 10 + '0', fd);
	}
	else if (ln < 10)
		ft_putchar_fd(ln + '0', fd);
}
