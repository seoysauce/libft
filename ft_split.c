/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:03:29 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/30 20:41:30 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			char_count(char const *s, char c)
{
	int ch_cnt;

	ch_cnt = 0;
	while (*s && *s != c)
	{
		ch_cnt++;
		s++;
	}
	return (ch_cnt);
}

int			word_count(char const *s, char c)
{
	int	wd_cnt;
	int	i;
	int	flag;

	i = 0;
	wd_cnt = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			wd_cnt++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (wd_cnt);
}

static char	**split_do(char const *s, char c, char **new, int wd_cnt)
{
	int	i;
	int	j;
	int	ch_cnt;

	i = 0;
	new[wd_cnt] = NULL;
	while (i < wd_cnt)
	{
		if ((ch_cnt = char_count(s, c)) != 0)
		{
			CHECK_MALLOC(new[i], sizeof(char) * (ch_cnt + 1));
			j = 0;
			while (*s && *s != c)
				new[i][j++] = *s++;
			new[i++][j] = '\0';
		}
		else
			s++;
	}
	return (new);
}

char		**ft_split(char const *s, char c)
{
	char	**new;
	int		wd_cnt;

	if (!s)
		return (NULL);
	wd_cnt = word_count(s, c);
	CHECK_MALLOC(new, sizeof(char *) * (wd_cnt + 1));
	return (split_do(s, c, new, wd_cnt));
}
