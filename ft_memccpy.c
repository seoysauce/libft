/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:59:58 by seojeong          #+#    #+#             */
/*   Updated: 2020/06/30 18:28:30 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)dst)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>
int		main(void)
{
	char str1[] = "Hello world!";
	char *str2 = "abcdefg";

	ft_memccpy(str1, str2, 'c', 5);
	//memccpy(str1, str2, 'c', 5);
	printf("%s\n", str1);
}
