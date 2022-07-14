/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:57:47 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 13:01:17 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_u(t_printdata *pd)
{
	unsigned int	u;
	char			*s;

	u = va_arg(pd->args, unsigned int);
	if (!u && u != 0)
		return ;
	s = ft_uitoa(u);
	ft_putstr_fd(s, 1);
	pd->ret += ft_strlen(s);
	free(s);
	return ;
}
