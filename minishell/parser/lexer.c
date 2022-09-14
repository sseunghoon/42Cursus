#include "../minishell.h"

int	make_token(t_info *info, int end, int start, char *str)
{
	char	*temp;

	temp = ft_strndup(&str[start], end + 1 - start);
	add_list(&info->dlist, temp);
	free(temp);
	return (1);
}

int	cut_bracket(char *str, t_info *info, int b_cnt, int b_pos)
{
	if (info->fo.i != info->fo.last_idx)
		make_token(info, info->fo.i - 1, info->fo.last_idx, str);
	info->fo.last_idx = info->fo.i;
	while (str[info->fo.i])
	{
		if (str[info->fo.i] == '(')
			b_cnt++;
		else if (str[info->fo.i] == ')')
		{
			b_cnt--;
			b_pos = info->fo.i;
		}
		if (!b_cnt && str[info->fo.i] == ')'
			&& make_token(info, b_pos, info->fo.last_idx, str))
			break ;
		info->fo.i++;
	}
	if (b_cnt)
		return (0);
	info->fo.i = b_pos;
	info->fo.last_idx = info->fo.i + 1;
	return (1);
}

int	first_opertaion(char *str, t_info *info)
{
	while (str[info->fo.i])
	{
		info->quote = 0;
		if (str[info->fo.i] == ' ' && info->fo.i == info->fo.last_idx)
			info->fo.last_idx = info->fo.i + 1;
		else if (str[info->fo.i] == ' '
			&& make_token(info, info->fo.i - 1, info->fo.last_idx, str))
			info->fo.last_idx = info->fo.i + 1;
		else if (str[info->fo.i] == '\'' || str[info->fo.i] == '\"')
		{
			info->quote = str[info->fo.i];
			info->fo.i++;
			while (str[info->fo.i] != info->quote)
				info->fo.i++;
		}
		else if (str[info->fo.i] == ')')
			return (put_syntaxerr_msg(")"));
		else if (str[info->fo.i] == '(' && !cut_bracket(str, info, 0, 0))
			return (put_syntaxerr_msg(")"));
		info->fo.i++;
	}
	if (info->fo.last_idx != info->fo.i)
		make_token(info, info->fo.i, info->fo.last_idx, str);
	return (1);
}

int	stick_redir(t_info *info)
{
	t_dlist	*tmp;
	char	*remove;

	tmp = info->dlist;
	while (tmp)
	{
		if (tmp->type == REDIR)
		{
			remove = tmp->token;
			tmp->token = ft_strjoin(remove, tmp->next->token);
			free(remove);
			remove = NULL;
			delete_node(&info->dlist, tmp->next);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	lexer(char *str, t_info *info)
{
	char	*lex_str;

	lex_str = ft_strdup(str);
	if (!first_opertaion(lex_str, info))
	{
		free(lex_str);
		return (0);
	}
	free(lex_str);
	tokenize(info);
	if (!info->dlist)
		return (0);
	if (!check_syntax(info))
		return (0);
	stick_redir(info);
	return (1);
}
