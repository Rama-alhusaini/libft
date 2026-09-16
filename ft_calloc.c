#include <stddef.h>
#include <stdlib.h>
void *ft_calloc (size_t n , size_t size)
{
	size_t i = 0;
	char *ptr;
	
	ptr = malloc(n * size);
		if(ptr == NULL)
			return (NULL);
	while (i < n *size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*arr;
	int	i;

	arr = ft_calloc(5, sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
}*/
