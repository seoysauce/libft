
#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t dst_len;
	size_t result;
	int	i;
	int	j;

	dst_len = ft_strlen(dst);
	result = ft_strlen(src);
	i = 0;
	j = dst_len;
	while ((src[i] != '\0') && i < (int)(dstsize - dst_len - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (dstsize < dst_len)
		result = result + dstsize;
	else
		result = result + dst_len;
	return (result);
}
/*
#include <stdio.h>
#include <string.h>
int		main(void)
{
	char str1[] = "Hello world!";
	char *str2 = "abcdefg";
	printf("%lu\n", strlcat(str1, str2, 4));
	
}
*/
