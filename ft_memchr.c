/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:00:30 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/05 18:00:47 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
		i++;
		s++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int		main(void)
{
	char *str1 = "Hello there!";
	char *new;

	new = memchr(str1, 't', 10);
	printf("%s\n", new);
}
*/
