/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:30:23 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/10 13:30:25 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	len;
	unsigned long	num;
	int				l;

	l = 1;
	num = n;
	len = ft_strlen(base);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (l);
	}
	if (num >= len)
	{
		l += ft_putnbr_base(num / len, base);
		ft_putchar_fd(base[num % len], 1);
	}
	else if (num < len)
		ft_putchar_fd(base[num], 1);
	return (l);
}
