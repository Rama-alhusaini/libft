/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:28:50 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 14:39:13 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex1(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count = ft_puthex1(n / 16);
		if (count == -1)
			return (-1);
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *s)
{
	int	count;

	if (s == NULL)
	{
		count = write(1, "(nil)", 5);
		if (count == -1)
			return (-1);
		return (count);
	}
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	count = ft_puthex1((unsigned long)s);
	if (count == -1)
		return (-1);
	return (count + 2);
}
