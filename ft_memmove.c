/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:30:24 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/02 17:09:11 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	unsigned char *dest;
	unsigned char *source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		
	}
	while (i < len)
	{
		dst[i] = src[i];
		
	}
	return (dst);
}
*/

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char str1[] = {};
	char *str2 = NULL;

	//memmove(str1, str2, 3);
	printf("%p\n", str1);
}
