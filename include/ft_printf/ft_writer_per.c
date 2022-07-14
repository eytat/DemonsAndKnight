/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:24:37 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 13:00:43 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Percent format output. */
void	ft_write_per(t_printdata *pd)
{
	char	per;

	per = va_arg(pd->args, int);
	if (pd->zero > 0)
	{
		ft_ws_zero("%", pd);
	}
	else if (pd->space)
		ft_ws_space("%", pd);
	else
	{
		ft_putchar_fd('%', 1);
		pd->ret++;
	}
	return ;
}
