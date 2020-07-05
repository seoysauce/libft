/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:03:29 by seojeong          #+#    #+#             */
/*   Updated: 2020/07/05 18:05:25 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_space(char ch)
{
	if (ch == ' ')
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		while (!(is_space(str[i])))
			i++;
		cnt += 1;
		i++;
	}
	return (cnt);
}

int	char_count(char *str)
{
	int	len;

	len = 0;
	while (str[len] && !(is_space(str[len])))
	{
		len++;
	}
	return (len);
}

char	**ft_split(char *str)
{
	char **arr;
	int	wd_cnt;
	int	i;
	int	j;
	int	wd_len;

	wd_cnt = word_count(str);
	arr = (char **)malloc(sizeof(char*) * (wd_cnt + 1));
	free(arr);
	arr[wd_cnt] = NULL;
	i = 0;
	while (i < wd_cnt)
	{
		wd_len = char_count(str);
		if (wd_len != 0)
		{
			arr[i] = (char *)malloc(sizeof(char) * (wd_len + 1));
			j = 0;
			while (j < wd_len)
			{
				arr[i][j] = *str++;
				j++;
			}
			arr[i][j] = '\0';
			i++;
		}
		else
		{
			str++;
		}
	}
	return (arr);
}
/*
int	main(void)
{
	char *str;
	str = "Hello world, my name is Seoyoung!";
	char **new;
	new = ft_split(str);
	

	int test = word_count(str);
	printf("%d\n", test);

	int i = 0;

	while (i < 7)
	{
		printf("%s\n", new[i]);
		i++;
	}
}
*/
