#include <stddef.h>

char	*ft_strnstr(const char *str, const char *substring, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (substring[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (i < len && str[i] == substring[j] && str[i])
		{
			i++;
			j++;
		}
		if (substring[j] == '\0')
			return ((char *)&str[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
