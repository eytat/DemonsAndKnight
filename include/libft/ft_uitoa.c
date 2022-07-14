/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:04:30 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/09 13:07:49 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_itoa function for unsigned int number. */
char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_digits_base(nb, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[len] = 0 + '0';
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
