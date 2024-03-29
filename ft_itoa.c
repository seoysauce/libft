/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:16:59 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/30 22:13:13 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	number_size(long number)
{
	size_t	size;

	size = (number < 0 ? 1 : 0);
	while (1)
	{
		number /= 10;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	size;
	long	num;

	num = n;
	size = number_size(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (num < 0)
	{
		new[0] = '-';
		num *= -1;
	}
	new[size] = '\0';
	while (1)
	{
		new[--size] = num % 10 + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (new);
}
