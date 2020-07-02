/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:23:00 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/02 22:46:16 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# define IS_WSPACE(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')

typedef struct	s_list
{
	void	*content;
	struct s_list *next;
}				t_list;
void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);



#endif
