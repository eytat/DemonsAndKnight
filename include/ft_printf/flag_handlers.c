/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:08:08 by amateo-r          #+#    #+#             */
/*   Updated: 2021/07/07 19:08:10 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	In this file there are the first part to manage 
	each flag of printf individually.
*/

#include "ft_printf.h"

/* Handler for flag "0". */
int	fh_zero(t_printdata *pd, const char *fmt, int index)
{
	int	pre_len;
	int	index_start;

	pre_len = 0;
	index_start = index;
	if (ch_flag(pd) == 1)
		return (0);
	while (ch_format(fmt[index]) == 0)
	{
		if (ft_isdigit(fmt[index]))
			index_start = index, pre_len++;
		else if ((fmt[index] == '-' || fmt[index] == '+'))
		{
			pd->space++;
			pd->minus++;
			pd->zero--;
		}
		index++;
	}
	if (pre_len > 0)
		pd->pre = ft_atoi(ft_substr(fmt, index_start - pre_len + 1, pre_len));
	pd->zero++;
	return (0);
}

// Handler for flag "-".
int	fh_minus(t_printdata *pd, const char *fmt, int index)
{
	fh_space(pd, fmt, index);
	pd->minus++;
	return (0);
}

// Handler for flag " ".
int	fh_space(t_printdata *pd, const char *fmt, int index)
{
	int	pre_len;
	int	index_start;
	int	signs;

	pre_len = 0;
	index_start = index;
	signs = -1;
	if (ch_flag(pd) == 1)
		return (0);
	while (ch_format(fmt[index]) == 0)
	{
		if (ft_isdigit(fmt[index]))
			index_start = index, pre_len++;
		else if ((fmt[index] == '-' || fmt[index] == '+'))
		{
			pd->minus++;
			signs++;
		}
		index++;
	}
	if (pre_len > 0)
		pd->pre = ft_atoi(ft_substr(fmt, index_start - pre_len + 1, pre_len));
	pd->space++;
	return (0);
}

// Handler for flag ".". Print only the number of
// characters specified with a number.
// 0 and nothing is the same. The varialbe signs count '+' and '-'.
int	fh_point(t_printdata *pd, const char *fmt, int index)
{
	int	pre_len;
	int	index_start;
	int	signs;

	pre_len = 0;
	index_start = index;
	signs = -1;
	while (ch_format(fmt[index]) == 0)
	{
		if (ft_isdigit(fmt[index]))
			index_start = index, pre_len++;
		else if ((fmt[index] == '-' || fmt[index] == '+'))
		{
			signs++;
			pd->space++;
			pd->minus++;
			pd->point--;
		}
		index++;
	}
	if (pre_len > 0)
		pd->pre = ft_atoi(ft_substr(fmt, index_start - pre_len + 1, pre_len));
	pd->point++;
	return (0);
}
