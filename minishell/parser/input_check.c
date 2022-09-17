/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/15 10:47:52 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_single_quote(t_info *info, char *str, int *i)
{
	if (*i != 0 && str[*i - 1] == '\\' && (*i)++)
		return (0);
	(*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	if (!str[*i])
		info->quote_flag = 1;
	else
		info->quote_flag = 0;
	return (1);
}

int	is_double_quote(t_info *info, char *str, int *i)
{
	if (*i != 0 && str[*i - 1] == '\\' && (*i)++)
		return (0);
	(*i)++;
	while ((str[*i] && str[*i] != '\"') || \
	(*i != 0 && str[*i] == '\"' && str[*i - 1] == '\\'))
		(*i)++;
	if (!str[*i])
		info->double_quote_flag = 1;
	else
		info->double_quote_flag = 0;
	return (1);
}

int	is_quotes(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s", str);
		if (str[i] == '\'' && info->double_quote_flag == 0)
		{
			if (!is_single_quote(info, str, &i))
				continue ;
		}
		else if (str[i] == '\"' && info->quote_flag == 0)
			if (!is_double_quote(info, str, &i))
				continue ;
		i++;
	}
	if (info->double_quote_flag == 0 && info->quote_flag == 0)
		return (1);
	else
		return (0);
}

int	space_check(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == 0 && i++)
			continue ;
		return (0);
	}
	return (1);
}

int	input_check(char *str)
{
	char	quote;
	int		i;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\"' && !quote)
			quote = '\"';
		else if (str[i] == '\"' && quote == '\"')
			quote = 0;
		else if (str[i] == '\'' && !quote)
			quote = '\'';
		else if (str[i] == '\'' && quote == '\'')
			quote = 0;
		i++;
	}
	if (quote)
	{
		if (quote == '\'')
			return (put_syntaxerr_msg("\'"));
		else if (quote == '\"')
			return (put_syntaxerr_msg("\""));
	}
	return (1);
}
