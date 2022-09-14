/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:55:21 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/16 22:23:48 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*node;

	node = NULL;
	while (lst != NULL)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode == 0)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
	}
	newnode = NULL;
	return (node);
}
