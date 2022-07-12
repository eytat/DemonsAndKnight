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

/**
 * DESCRIPTION:
 * Checks that all characters of string str are
 * same to c.
 * PARAMETERS:
 * @param	const char	*str	String to check.
 * @param	int			c		Character to find.
 * RETURN:
 * If there is a different character to c returns 1 else
 * return 0.
 */
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
