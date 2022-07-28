/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:47:23 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static t_list	*ft_lstminimap(t_list *lst, \
void *(*f)(void *), void (*del)(void *), t_list *new_lst)
{
	t_list	*p;
	t_list	*q;

	q = new_lst;
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		if (p == NULL)
		{
			while (new_lst)
			{
				p = new_lst->next;
				del(new_lst->content);
				free(new_lst);
				new_lst = p;
			}
			return (0);
		}
		q->next = p;
		q = q->next;
		p = NULL;
		lst = lst->next;
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	if (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == NULL)
			return (0);
		lst = lst->next;
		if (lst)
		{
			new_lst = ft_lstminimap(lst, f, del, new_lst);
			if (new_lst == NULL)
				return (0);
		}
	}
	return (new_lst);
}
