
#include "libft.h"

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t src_len;
	size_t len;

	src_len = ft_strlen(src);
	if (dstsize)
	{
		len = (src_len >= dstsize) ? dstsize - 1 : src_len; 
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (src_len);
}
/*
#include <string.h>
#include <stdio.h>
int		main(void)
{
	char str1[] = "hello";
	char *str2 = "123456";

	printf("%lu\n", ft_strlcpy(str1, str2, 3));
	printf("%s\n", str1);
}
*/
