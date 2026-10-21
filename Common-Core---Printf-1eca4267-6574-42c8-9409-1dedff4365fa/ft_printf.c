/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhusai <ralhusai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:22:09 by ralhusai          #+#    #+#             */
/*   Updated: 2026/10/21 15:29:33 by ralhusai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ch(char c, va_list x)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = ft_putchar(va_arg(x, int));
	if (c == 's')
		result = ft_putstr(va_arg(x, char *));
	if (c == 'p')
		result = ft_putptr(va_arg(x, void *));
	if (c == 'd' || c == 'i')
		result = ft_puti_d(va_arg(x, int));
	if (c == 'u')
		result = ft_putunsigned(va_arg(x, unsigned int));
	if (c == 'x')
		result = ft_puthex(va_arg(x, unsigned int));
	if (c == 'X')
		result = ft_puthex_upper(va_arg(x, unsigned int));
	if (c == '%')
		result = ft_putchar('%');
	return (result);
}

static int	ft_process(const char *str, int *i, va_list x)
{
	int	result;

	result = 0;
	if (str[*i] == '%')
	{
		(*i)++;
		if (str[*i] != '\0')
			result = ft_ch(str[*i], x);
	}
	else
		result = ft_putchar(str[*i]);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	x;
	int		count;
	int		i;
	int		result;

	if (str[0] == '\0')
		return (-1);
	count = 0;
	i = 0;
	va_start(x, str);
	while (str[i])
	{
		result = ft_process(str, &i, x);
		if (result == -1)
		{
			va_end(x);
			return (0);
		}
		count += result;
		i++;
	}
	va_end(x);
	return (count);
}
