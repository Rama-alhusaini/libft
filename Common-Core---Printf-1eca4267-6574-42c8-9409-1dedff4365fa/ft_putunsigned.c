/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:30:36 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 14:40:37 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		count;
	int		result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putunsigned(n / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
