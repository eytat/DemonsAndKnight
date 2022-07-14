/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:31:27 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 13:04:52 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_pad(t_printdata *pd)
{
	if (pd->pad > 0)
		pd->ret += write(1, "0x", 2);
	return ;
}

void	ft_write_x(t_printdata *pd, int c)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(pd->args, unsigned int);
	if (!n)
	{
		pd->ret += write(1, "0", 1);
		return ;
	}
	len = ft_digits_base(n, 16);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (!str)
		return ;
	ft_write_pad(pd);
	str = ft_itoa_base(str, n, 16, c);
	while (str && len-- > 0)
		pd->ret += write(1, &str[len], 1);
	free(str);
	return ;
}
