/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:25:36 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 14:38:09 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	char	*hex;
	int		count;
	int		result;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		result = ft_puthex(n / 16);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}
