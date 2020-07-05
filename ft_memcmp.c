
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *str1 = "aaaaaaa";
	char *str2 = "aaccaaa";

	//printf("%d\n", memcmp(str1, str2, 5));
	printf("%d\n", memcmp(str1, str2, 5));
}
*/
