/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:32:14 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/12 16:57:13 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr;
	t_list	*new_curr;

	if (!lst)
		return (NULL);
	if (!(new_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	curr = lst->next;
	new_curr = new_lst;
	while (curr != NULL)
	{
		if (!(new_curr->next = ft_lstnew(f(curr->content))))
			ft_lstclear(&new_lst, del);
		new_curr = new_curr->next;
		curr = curr->next;
	}
	return (new_lst);
}
