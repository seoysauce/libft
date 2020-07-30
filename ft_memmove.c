/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:30:24 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/29 17:57:42 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	x = -1;
	if (pdst < psrc)
		while (++x < len)
			pdst[x] = psrc[x];
	else
		while (len-- > 0)
			pdst[len] = psrc[len];
	return (dst);
}

/*
#include <stdio.h>
int		main(void)
{
	char str[] = "memmove can be very useful......";
	ft_memmove(str + 20, str + 15, 11);
	puts(str);
}
*/
