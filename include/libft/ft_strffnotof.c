/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strffnotof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:32:41 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/20 10:38:14 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Todos los caracteres son iguales.
int	ft_strffnotof(const char *str, int c)
{
	int	i;
	int	len;

	len = ft_strlen(str) - 1;
	i = -1;
	while (++i < len)
		if (str[i] != c)
			return (1);
	return (0);
}
