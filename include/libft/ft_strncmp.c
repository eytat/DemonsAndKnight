/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:57:57 by amateo-r          #+#    #+#             */
/*   Updated: 2021/05/25 10:58:09 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * DESCRIPTION:
 * Compare not more than n characters between strings s1 and s2.
 * PARAMETERS:
 * @param	const char	*s1	String to compare with s2.
 * @param	const char	*s2	String to compare with s1.
 * @param	size_t		n	Number of characters to compare.
 * RETURN:
 * If the strings are different return the difference between the int code
 * characters that aren't equal. If there isn't difference return 0.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i] && str1[i] != '\0') && i < n)
		i++;
	if (i == n)
		i--;
	return (str1[i] - str2[i]);
}
