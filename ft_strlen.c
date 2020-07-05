
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
	{
		len++;
	}
	return (len);
}
/*
#include <string.h>
#include <stdio.h>
int		main(void)
{
	char *str = "Hello world!";

	printf("%lu\n", ft_strlen(str));
}
*/
