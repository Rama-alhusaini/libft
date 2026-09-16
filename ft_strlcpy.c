#include <stddef.h>

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = 0;
	i = 0;
	while (src[srcsize] != '\0')
	{
		srcsize++;
	}
	if (dstsize > 0)
	{
		dstsize--;
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
/*
#include <stdio.h>

int main(void)
{
    char src[] = "Hello";
    char dst[10];
    size_t result;

    result = strlcpy(dst, src, sizeof(dst));

    printf("dst: %s\n", dst);
    printf("return: %zu\n", result);

    return (0);
}*/
