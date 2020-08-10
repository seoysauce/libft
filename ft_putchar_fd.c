/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:31:45 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/10 17:24:38 by seojeong         ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uni_c[2];
	int				i;

	i = 0;
	if ((unsigned char)c >= 128)
	{
		uni_c[0] = (unsigned char)c / 0x40 + UTF8_B2;
		uni_c[1] = (unsigned char)c % 0x40 + UTF8_BX;
		while (i < 2)
			write(fd, &uni_c[i++], 1);
	}
	else
		write(fd, &c, 1);
}
