#include <stdlib.h>
#include "libft.h"

int	is_in_set(char c, const char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*copy_str(char const *s1, char *str, int s, int i)
{
	int	m;

	m = 0;
	while (m < s)
	{
		str[m] = s1[i];
		i++;
		m++;
	}
	str[m] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		e;
	int		s;
	char	*str;

	i = 0;
	while (s1[i] != '\0' && is_in_set(s1[i], set) == 1)
		i++;
	e = ft_strlen(s1) - 1;
	while (e >= 0 && is_in_set(s1[e], set) == 1)
		e--;
	if (e < i)
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	s = e - i + 1;
	str = malloc((s + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (copy_str(s1, str, s, i));
}
