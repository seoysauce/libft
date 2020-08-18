/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:18:37 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/17 13:44:07 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s1);
	duplicate = ft_calloc(len + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_memcpy(duplicate, s1, len);
	duplicate[len] = '\0';
	return (duplicate);
}
