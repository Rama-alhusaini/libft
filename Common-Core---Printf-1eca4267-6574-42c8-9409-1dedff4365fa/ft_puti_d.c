/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:27:43 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 14:38:49 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puti_d(int n)
{
	char	c;
	int		count;
	int		result;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		num = -num;
	}
	if (num >= 10)
	{
		result = ft_puti_d(num / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	c = num % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
