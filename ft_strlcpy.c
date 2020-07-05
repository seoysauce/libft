/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:01:53 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/05 18:02:27 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t dstsize)
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
