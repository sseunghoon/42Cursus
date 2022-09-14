#include "../minishell.h"

int	is_sep_token(char *str, int i)
{
	if (str[i] == '<' || str[i] == '>'
		|| (str[i] == '&' && str[i + 1] == '&') || str[i] == '|')
		return (1);
	return (0);
}

int	pass_quote(char *token, int i)
{
	char	quote;

	quote = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !quote)
			quote = '\'';
		else if (token[i] == '\'' && quote == '\'')
		{
			quote = 0;
			return (i);
		}
		else if (token[i] == '\"' && !quote)
			quote = '\"';
		else if (token[i] == '\"' && quote == '\"')
		{
			quote = 0;
			return (i);
		}
		i++;
	}
	return (i);
}

int	split_token(char *token, t_dlist *curr, int i, int quote)
{
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '\"')
			i = pass_quote(token, i);
		else if (!is_sep_token(token, i))
		{
			while (token[i] && !is_sep_token(token, i))
				i++;
			if (is_sep_token(token, i))
				cut_node(curr, i - 1);
			return (1);
		}
		else if (is_sep_token(token, i))
		{
			if (token[i + 1] == token[i])
				cut_node(curr, i + 1);
			else
				cut_node(curr, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_complete_sep(char *token)
{
	if (!ft_strncmp(token, "<<", 3) || !ft_strncmp(token, "||", 3) \
	|| !ft_strncmp(token, ">>", 3) || !ft_strncmp(token, "&&", 3) \
	|| !ft_strncmp(token, "<", 2) || !ft_strncmp(token, ">", 2) \
	|| !ft_strncmp(token, "|", 2))
		return (1);
	return (0);
}

void	tokenize(t_info *info)
{
	t_dlist	*curr;

	curr = info->dlist;
	while (curr)
	{
		if (curr->token[0] == '(' || is_complete_sep(curr->token))
		{
			curr = curr->next;
			continue ;
		}
		split_token(curr->token, curr, 0, 0);
		curr = curr->next;
	}
}
