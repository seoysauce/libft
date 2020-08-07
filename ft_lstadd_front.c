/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:48:10 by seojeong          #+#    #+#             */
/*   Updated: 2020/08/07 17:47:18 by seojeong         ###   ########.fr       */
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
/*
#include <stdio.h>
int main(){
	t_list* t1;
	t_list* t2;
	t_list tt1;
	t1 = &tt1;
	t_list tt2;
	t2 = &tt2;
	tt2.next = NULL;
	tt1.next = NULL;
	ft_lstadd_front(t1, t2);
	printf("t1->next : %p t2->next : %p &t1 : %p\n ", t1->next, t2->next, t1);

}
*/
