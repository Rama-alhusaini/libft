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
