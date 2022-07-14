/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:50:34 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/05 15:50:36 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Esencialmente un puntero es en formato %#x %llx %lx
// Exist esta opción: uintptr_t. Como es un tipo de dato, técnicmante
// , es legal, puesto que no es una función prohibida.
/* Pointer format output. */
void	ft_write_p(t_printdata *pd)
{
	unsigned long	point;
	int				len;

	len = 2;
	point = (unsigned long)va_arg(pd->args, void *);
	if ((!point && pd->pre > 0) || point == 0)
	{
		pd->ret += write(1, "0x0", 3);
		return ;
	}
	if (!(!point))
		len += ft_digits_base(point, 16);
	else
		pd->pre = pd->pre + 2 - len;
	pd->ret += write(1, "0x", 2);
	while (pd->pre-- > 0)
		pd->ret += write(1, "0", 1);
	if (!(!point))
		pd->ret += ft_putnbr_base(point, "0123456789abcdef");
}
