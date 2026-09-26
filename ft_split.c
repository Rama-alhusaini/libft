#include "libft.h"

int	count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*print(char const *str, char c)
{
	int		i;
	int		len;
	char	*s;

	len = word_len(str, c);
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	free_split(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**re_str;
	int		j;
	int		k;

	re_str = malloc((count(s, c) + 1) * sizeof(char *));
	if (re_str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s[k] != '\0')
	{
		while (s[k] != '\0' && s[k] == c)
			k++;
		if (s[k] == '\0')
			break ;
		re_str[j] = print(&s[k], c);
		if (re_str[j] == NULL)
		{
			free_split(re_str, j);
			return (NULL);
		}
		k += word_len(&s[k], c);
		j++;
	}
	re_str[j] = NULL;
	return (re_str);
}
