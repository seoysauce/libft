/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:57:37 by seojeong          #+#    #+#             */
/*   Updated: 2020/06/29 22:48:21 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*pstr;

	i = 0;
	pstr = (unsigned char *)str;
	while (i < len)
	{
		pstr[i] = c;
		i++;
	}
	return (str);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char str[] = "Hello world!";
	void *new1;
	//void *new2;

	new1 = ft_memset(str, '-', 4);
	printf("%s\n", new1);
	//new2 = memset(str, '-', 4);
	//printf("%s\n", new2);
}
