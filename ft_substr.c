#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			l;
	unsigned int	st;
	char			*substr;

	i = 0;
	l = 0;
	st = start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[st] != '\0' && l < len)
	{
		substr[i] = s[st];
		i++;
		st++;
		l++;
	}
	substr[i] = '\0';
	return (substr);
}
