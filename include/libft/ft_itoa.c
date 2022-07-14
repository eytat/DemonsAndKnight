/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:08:36 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/03 11:08:39 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_lp(int n, char *str, int pos)
{
	if (n > 9)
	{
		pos = ft_putnbr_lp(n / 10, str, pos);
		pos++;
		pos = ft_putnbr_lp(n % 10, str, pos);
	}
	else
		str[pos] = n + '0';
	return (pos);
}

/* Convert number into string. */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_digits(n) + 1));
	if (str != 0)
	{
		if (n == -2147483648)
			return (ft_strcpy (str, "-2147483648"));
		if (n < 0)
		{
			n = -n;
			str[i++] = '-';
		}
		i = ft_putnbr_lp (n, str, i) + 1;
		str[i] = '\0';
	}
	else
		return (0);
	return (str);
}
