/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:02:47 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/30 21:12:22 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_len;
	size_t	result;
	int		i;
	int		j;

	dst_len = ft_strlen(dst);
	result = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dstsize > dst_len)
	{
		while ((src[i] != '\0') && i < (int)(dstsize - dst_len - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dstsize < dst_len)
		result = result + dstsize;
	else
		result = result + dst_len;
	return (result);
}
