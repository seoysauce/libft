/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:01:22 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/12 00:17:39 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

/*
** #include <string.h>
** #include <stdio.h>
** int		main(void)
** {
** 	char *str = "Hello world!";
**
** 	printf("%lu\n", ft_strlen(str));
** }
*/
