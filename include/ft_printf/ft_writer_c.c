/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:59:32 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 12:57:45 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Errores en 5, 8, 9
void	ft_write_c(t_printdata *pd)
{
	char	c;
	char	*s;

	c = va_arg(pd->args, int);
	s = malloc (sizeof(char));
	*s = c;
	if (pd->zero > 0)
		ft_ws_zero(s, pd);
	else if (pd->space)
		ft_ws_space(s, pd);
	else if (pd->point)
		ft_ws_point(s, pd);
	else
	{
		ft_putchar_fd(c, 1);
		pd->ret++;
	}
	free (s);
	return ;
}
