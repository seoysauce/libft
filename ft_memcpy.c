/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:59:04 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/03 22:39:48 by seoyoungj        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL & src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int		main(void)
{
	//char str1[] = "Hello world!";
	//char str2[] = "abcdefg";
	char *str1 = NULL;
	char *str2 = NULL;
	ft_memcpy(str1, str2, 5);
	//memcpy(str1, str2, 10);
	printf("%s\n", str1);
	printf("%lu\n", sizeof(str1));
}
*/
