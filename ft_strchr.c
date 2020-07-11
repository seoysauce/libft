/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:04:38 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/12 01:00:32 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s+i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s+i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
     char *new;

     new = ft_strchr("", '\0');
     printf("%s\n", new);
}
*/
