/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:07:43 by littley           #+#    #+#             */
/*   Updated: 2022/09/16 16:53:11 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	key_check(char *token, int *i, int flag)
{
	if (ft_isdigit(token[0]) || token[0] == '=')
	{
		if (flag)
			ft_putstr_fd("morningshell: unset: \'", 2);
		else
			ft_putstr_fd("morningshell: export: \'", 2);
		ft_putstr_fd(token, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
		return (1);
	}
	while (token[(*i)] && token[(*i)] != '=')
		(*i)++;
	if (flag && token[(*i)] == '=')
	{
		ft_putstr_fd("morningshell: unset: \'", 2);
		ft_putstr_fd(token, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
		return (1);
	}	
	if (!token[(*i)])
		return (1);
	return (0);
}

int	unset(t_info *info, t_dlist *list, int i)
{
	t_dlist	*tmp;
	char	**key;
	int		check;

	key = make_str_arr(list->next);
	while (key[i])
	{
		check = 0;
		tmp = info->env;
		if (key_check(key[i], &check, 1) && ++i)
			continue ;
		while (tmp)
		{
			if (ft_strncmp(tmp->token, key[i], ft_strlen(key[i]) + 1) == '=')
				break ;
			tmp = tmp->next;
		}
		if (!tmp && ++i)
			continue ;
		delete_node(&info->env, tmp);
		i++;
	}
	free(key);
	return (0);
}

int	env(t_info *info, int flag)
{
	t_dlist	*temp;
	int		i;

	temp = info->env;
	while (temp != NULL)
	{
		i = -1;
		if (flag == 1)
		{
			printf("declare -x ");
			while (temp->token[++i] && temp->token[i] != '=')
				printf("%c", temp->token[i]);
			if (temp->token[i] == '=')
			{
				printf("=\"");
				printf("%s", &temp->token[++i]);
				printf("\"");
			}
		}
		else
			printf("%s", temp->token);
		printf("\n");
		temp = temp->next;
	}
	return (0);
}

int	env_check(t_info *info, t_dlist *env_list, char *key_value, int *i)
{
	char	*temp;
	t_dlist	*unset_list;

	while (env_list)
	{
		if (!ft_strncmp(key_value, env_list->token, (*i)))
		{
			temp = ft_strndup(env_list->token, (*i));
			unset_list = create_list();
			unset_list->next = create_list();
			unset_list->next->token = temp;
			unset(info, unset_list, 0);
			free(temp);
			free(unset_list->next);
			free(unset_list);
			break ;
		}
		env_list = env_list->next;
	}
	return (0);
}

int	export(t_info *info, t_dlist *list)
{
	int		i;
	t_dlist	*curr;
	t_dlist	*env_list;

	curr = list->next;
	env_list = info->env;
	if (!curr)
	{
		env(info, 1);
		return (0);
	}
	while (curr)
	{
		i = 0;
		if (!key_check(curr->token, &i, 0) && ft_strchr(curr->token, '=')
			&& !env_check(info, env_list, curr->token, &i))
			add_list(&info->env, curr->token);
		curr = curr->next;
	}
	return (0);
}
