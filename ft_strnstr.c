/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 01:01:13 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/30 20:37:24 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		if (needle[j] == '\0')
			return ((char *)haystack + i - j);
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (haystack[i] == '\0' || i >= len)
			return (NULL);
		i++;
	}
}
