/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:19:31 by amateo-r          #+#    #+#             */
/*   Updated: 2021/07/13 18:20:08 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Impression for flag zero */
void	ft_ws_zero(char *s, t_printdata *pd)
{
	int	i;
	int	s_len;

	i = -1;
	s_len = ft_strlen(s);
	if (pd->pre > 0)
	{
		while (++i < (pd->pre - s_len))
		{
			pd->ret++;
			ft_putchar_fd('0', 1);
		}
	}
	ft_putstr_fd(s, 1);
	pd->ret += s_len;
	return ;
}

void	ft_ws_space(char *s, t_printdata *pd)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(s);
	if (pd->minus)
		ft_putstr_fd(s, 1);
	if (pd->pre > 0)
	{
		while (++i < pd->pre - len)
		{
			pd->ret++;
			ft_putchar_fd(' ', 1);
		}
	}
	if (!pd->minus)
		ft_putstr_fd(s, 1);
	pd->ret += len;
	return ;
}

/* Impression for flag point. */
void	ft_ws_point(char *s, t_printdata *pd)
{
	int		i;
	int		len;
	char	c;

	i = -1;
	len = ft_strlen(s);
	if (pd->pre > 0)
	{
		if (pd->pre > len && !pd->minus)
			pd->ret += write(1, s, len);
		else
		{
			while (++i < pd->pre)
			{
				if (pd->minus)
					c = ' ';
				else
					c = s[i];
				pd->ret += write (1, &c, 1);
			}
		}
	}
	return ;
}

/* Write a string. */
void	ft_write_s(t_printdata *pd)
{
	char	*s;

	s = va_arg(pd->args, char *);
	if (!s)
	{
		pd->ret += write(1, "(null)", 6);
		return ;
	}
	if (pd->zero > 0)
		ft_ws_zero(s, pd);
	else if (pd->space > 0)
		ft_ws_space(s, pd);
	else if (pd->point > 0)
		ft_ws_point(s, pd);
	else
	{
		ft_putstr_fd(s, 1);
		pd->ret += ft_strlen(s);
	}
	return ;
}
