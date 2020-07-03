/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:30:24 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/03 22:41:21 by seoyoungj        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			step;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		step = -1;
		dest = (unsigned char *)(dst + len - 1);
		source = (unsigned char *)(src + len - 1);
	}
	while (i < len)
	{
		*dest = *source;
		dest = dest + step;
		source += step;
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char str1[] = "Hello my name is Jiyong!";
	//memmove(str1 + 17, str1, 5);
	ft_memmove(str1 + 17, str1, 5);
	printf("%s\n", str1);
}
*/
