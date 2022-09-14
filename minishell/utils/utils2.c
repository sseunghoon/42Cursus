/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: littley <littley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:30:31 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/13 09:54:02 by littley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrep(char *token, char *value, int i)
{
	char	*s1;
	char	*s2;
	char	*ret;

	token[i] = '\0';
	s1 = ft_strdup(token);
	i++;
	while (token[i] && token[i] != ' ' && token[i] != '\"'
		&& token[i] != '\'' && token[i] != '$')
		i++;
	s2 = ft_strdup(token + i);
	free(token);
	ret = ft_strjoin(s1, value);
	free(s1);
	s1 = ret;
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

void	cut_node(t_dlist *curr, int i)
{
	t_dlist	*new;
	char	*tmp1;
	char	*tmp2;
	char	*remove;

	remove = curr->token;
	new = create_list();
	tmp1 = ft_strndup(remove, i + 1);
	tmp2 = ft_strdup(&remove[i + 1]);
	free(remove);
	curr->token = tmp1;
	new->token = tmp2;
	new->next = curr->next;
	if (curr->next)
		curr->next->prev = new;
	curr->next = new;
	new->prev = curr;
}
