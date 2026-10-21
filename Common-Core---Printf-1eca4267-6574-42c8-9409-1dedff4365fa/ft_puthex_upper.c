/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:26:38 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 14:38:31 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	char	*hex;
	int		count;
	int		result;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		result = ft_puthex_upper(n / 16);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}
