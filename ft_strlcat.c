#include <stddef.h>

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	dst_len = 0;
	while (dst[i] != '\0')
		i++;
	dst_len = i;
	while (src[j] != '\0')
		j++;
	if (dstsize <= dst_len)
		return (dstsize + j);
	i = dst_len;
	j = 0;
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + j);
}
