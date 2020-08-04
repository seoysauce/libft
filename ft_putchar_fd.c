/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:31:45 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/04 22:51:45 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
*/

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
** Beyond Unicode, consideration is needed for UTF-8 and UTF-16
** But, as
** http://wiki.kldp.org/wiki.php/32bitCodeTo64bit about 32-bit to 64-bit
** http://archive.is/HUJr2 http://archive.is/gb41i
** https://stackoverrun.com/ko/q/11516787
** UTF-8:
** (-00007F:ASCII) 1xxxxxxx
** (000080-0007FF) 110xxxxx 10xxxxxx
** (000800-00FFFF) 1110xxxx 10xxxxxx 10xxxxxx
** (010000-10FFFF) 11110zzz 10zzxxxx 10xxxxxx 10xxxxxx
*/

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uni_c;

	if ((unsigned char)c >= UTF8_CP1)
	{
		uni_c = (unsigned char)c / 0x40 + UTF8_B2;
		write(fd, &uni_c, 1);
		uni_c = (unsigned char)c % 0x40 + UTF8_BX;
		write(fd, &uni_c, 1);
	}
	else
		write(fd, &c, 1);
}


/*
include <stdio.h>
#include <unistd.h>

char happy[] = { 0xe2, 0x98, 0xba };  // U+263A

int main()
{
   write(1, happy, 3);
   return 0;
}
*/
