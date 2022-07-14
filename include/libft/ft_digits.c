/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:43:05 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/09 12:43:10 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Count digits of a number. */
int	ft_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
