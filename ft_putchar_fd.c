/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:31:45 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/06 16:29:35 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define UTF8_CP1 0x80
#define UTF8_CP2 0x800
#define UTF8_CP3 0x10000
#define UTF8_CP4 0x200000

#define UTF8_BX 0x80
#define UTF8_B2 0xC0
#define UTF8_B3 0xE0
#define UTF8_B4 0xF0
#define UTF8_B5 0xF8

/*
** UTF-8:
** (-00007F:ASCII) 1xxxxxxx
** (000080-0007FF) 110xxxxx 10xxxxxx
** (000800-00FFFF) 1110xxxx 10xxxxxx 10xxxxxx
** (010000-10FFFF) 11110zzz 10zzxxxx 10xxxxxx 10xxxxxx
*/

int		*unicode_cal(int c, int *uni_c)
{
	if (c <= 0x07ff)
	{
		uni_c[0] = c / 0x40 + UTF8_B2;
		uni_c[1] = c % 0x40 + UTF8_BX;
	}
	else if (c <= 0xffff)
	{
		uni_c[0] = c / 0x1000 + UTF8_B3;
		uni_c[1] = c % 0x1000 / 0x40 + UTF8_BX;
		uni_c[2] = c % 0x40 + UTF8_BX;
	}
	else if (c <= 0x10ffff)
	{
		uni_c[0] = c / 0x40000 + UTF8_B4;
		uni_c[1] = c % 0x40000 / 0x1000 + UTF8_BX;
		uni_c[2] = c % 0x1000 / 0x40 + UTF8_BX;
		uni_c[3] = c % 0x40 + UTF8_BX;
	}
	return (uni_c);
}

void	ft_putchar_fd(int c, int fd)
{
	int	uni_c[4];
	int	i;

	i = 0;
	if (c <= 0x7f)
		write(fd, &c, 1);
	else if (c <= 0x07ff)
	{
		unicode_cal(c, uni_c);
		while (i < 2)
			write(fd, &uni_c[i++], 1);
	}
	else if (c <= 0xffff)
	{
		unicode_cal(c, uni_c);
		while (i < 3)
			write(fd, &uni_c[i++], 1);
	}
	else if (c <= 0x10ffff)
	{
		unicode_cal(c, uni_c);
		while (i < 4)
			write(fd, &uni_c[i++], 1);
	}
}
