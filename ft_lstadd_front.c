/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:48:10 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/07 18:48:19 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_front2(t_list *lst, t_list new)
{
	new.next = lst;
	lst = &new;
}
#include <stdio.h>
int main(){
	t_list * head;
	t_list t1;
	t_list t2;
	t_list t3;
	t1.next = &t2;
	t2.next = &t3;
	head = &t1;
	t_list t0;
	printf("&t1 : %p\n", &t1);
	ft_lstadd_front(&head, &t0);
	printf("t0.next = %p\n ", t0.next);

}

