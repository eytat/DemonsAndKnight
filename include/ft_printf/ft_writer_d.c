/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:23:58 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 12:58:54 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_stupid_sign(t_printdata *pd, int sign, int d)
{
	if (sign == 1)
	{
		pd->pre -= 1;
		d *= -1;
		ft_putchar_fd('-', 1);
		pd->ret++;
	}
	return (d);
}

void	ft_write_d(t_printdata *pd)
{
	char	*s;
	int		d;
	int		sign;

	d = va_arg(pd->args, int);
	sign = 0;
	if (!d && d != 0)
		return ;
	if (d < 0)
		sign = 1;
	s = ft_itoa(d);
	ft_putstr_fd(s, 1);
	pd->ret += ft_strlen(s);
	free(s);
	return ;
}
