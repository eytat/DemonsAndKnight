/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:00:32 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 12:54:22 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Evaluate the characteristics of the allowed formats (cspdiuxX%). */
t_printdata	*ft_eval_format(const char *fmt, int index, t_printdata *pd)
{
	if (fmt[index] == 'c')
		ft_write_c(pd);
	else if (fmt[index] == 's')
		ft_write_s(pd);
	else if (fmt[index] == 'p')
		ft_write_p(pd);
	else if (fmt[index] == 'd' || fmt[index] == 'i')
		ft_write_d(pd);
	else if (fmt[index] == 'u')
		ft_write_u(pd);
	else if (fmt[index] == 'x' || fmt[index] == 'X')
		ft_write_x(pd, fmt[index] - 23);
	else if (fmt[index] == '%')
		pd->ret += write(1, "%", 1);
	return (pd);
}

/*	Para que cada vez que se registren los datos de un formato,
	no haya solapamiento con el anterior. */
t_printdata	*ft_reset_pd(t_printdata *pd)
{
	pd->pre = 0;
	pd->pad = 0;
	pd->zero = 0;
	pd->minus = 0;
	pd->space = 0;
	pd->sign = 0;
	pd->apost = 0;
	pd->point = 0;
	return (pd);
}

/*	Evaluate the type of formats when '%' is detected. */
int	ft_eval_flag(const char *fmt, int index, t_printdata *pd)
{
	int	index_start;

	index_start = index;
	ft_reset_pd(pd);
	while (ch_format(fmt[index]) == 0)
		index++;
	ft_eval_format(fmt, index, pd);
	return (index);
}
