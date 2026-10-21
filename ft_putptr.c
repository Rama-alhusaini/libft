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
