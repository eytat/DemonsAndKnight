/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:47:19 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/09 12:47:24 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Count digits of a number with base format. */
int	ft_digits_base(unsigned long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
