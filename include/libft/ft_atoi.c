/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:10:55 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/03 11:10:57 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isodd(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static int	ch_size(const char *str, int sign, int i)
{
	int	count;

	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		count++;
	}
	if (ft_strlen(str) > 18 && sign == -1 && count > 18)
		return (0);
	else if (ft_strlen(str) > 18 && count > 18)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	nb;

	nb = 0;
	sign = 1;
	i = ft_isodd(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (ch_size(str, sign, i) == 0)
		return (0);
	else if (ch_size(str, sign, i) == -1)
		return (-1);
	return ((int)nb * sign);
}
