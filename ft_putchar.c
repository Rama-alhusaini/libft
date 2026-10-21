int	ft_putchar(char chr)
{
	if (write(1, &chr, 1) == -1)
		return (-1);
	return (1);
}
