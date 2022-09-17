/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/14 09:53:39 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tree(t_tree *myself)
{
	if (!myself)
		return ;
	myself->dlist = get_first(myself->dlist);
	if (myself->dlist)
		delete_dlist(myself->dlist);
	free_tree(myself->left_child);
	free_tree(myself->right_child);
	free(myself);
}

t_dlist	*check_priority(t_dlist *curr)
{
	t_dlist	*priority;

	while (curr->next)
		curr = curr->next;
	priority = curr;
	while (curr)
	{
		if (curr->type < priority->type)
			priority = curr;
		curr = curr->prev;
	}
	return (priority);
}

t_tree	*make_tree(t_tree *myself, t_dlist *dlist)
{
	t_dlist		*left;
	t_dlist		*right;
	t_dlist		*node;

	node = check_priority(dlist);
	if (!myself)
		myself = ft_calloc(1, sizeof(t_tree));
	myself->dlist = node;
	if (node->type >= 4)
		return (myself);
	left = node->prev;
	right = node->next;
	if (left)
		left->next = 0;
	if (right)
		right->prev = 0;
	left = get_first(node->prev);
	node->next = 0;
	node->prev = 0;
	if (left)
		myself->left_child = make_tree(myself->left_child, left);
	if (right)
		myself->right_child = make_tree(myself->right_child, right);
	return (myself);
}
