#include <stdlib.h>

int	num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*n_to_str(char *s, int len, long num, int n)
{
	int	i;
	int	x;

	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
		num = -num;
	}
	len--;
	while (i < num_len(n))
	{
		x = num % 10 + '0';
		num = num / 10;
		s[len] = x;
		i++;
		len--;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	long	num;

	len = num_len(n);
	num = n;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	return (n_to_str(s, len, num, n));
}
