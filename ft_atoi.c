/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:41:32 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/04 20:58:30 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (IS_WSPACE(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			minus *= -1;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (i > 19 || res >= LLONG_MAX)
		return (minus == 1 ? -1 : 0);
	return (res * minus);
}

