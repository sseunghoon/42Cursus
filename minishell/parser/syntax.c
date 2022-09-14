#include "../minishell.h"

extern int	g_exit_code;

int	put_syntaxerr_msg(char *token)
{
	printf("minishell: syntax error near unexpected token `%s'\n", token);
	g_exit_code = 258;
	return (0);
}

int	init_syntax(t_info *info)
{
	t_dlist	*curr;

	curr = info->dlist;
	while (curr)
	{
		if (!ft_strncmp(curr->token, "&&", 3)
			|| !ft_strncmp(curr->token, "||", 3))
			curr->type = LINE;
		else if (!ft_strncmp(curr->token, "|", 2))
			curr->type = PIPE;
		else if (!ft_strncmp(curr->token, "<", 1)
			|| !ft_strncmp(curr->token, ">", 1))
			curr->type = REDIR;
		else if (curr->token[0] == '(')
			curr->type = BRACKET;
		else
			curr->type = WORD;
		curr = curr->next;
	}
	return (1);
}

int	check_last(t_dlist *curr)
{
	if (curr->type != WORD && curr->type != BRACKET)
	{
		if (curr->type == REDIR)
			return (put_syntaxerr_msg("newline"));
		else
			return (put_syntaxerr_msg(curr->token));
	}
	return (1);
}

int	check_syntax_opt(t_dlist *curr)
{
	int	ret;

	ret = 1;
	if (curr->type == LINE)
		ret = check_line(curr);
	else if (curr->type == PIPE)
		ret = check_pipe(curr);
	else if (curr->type == REDIR)
		ret = check_redir(curr);
	else if (curr->type == WORD)
		ret = check_word(curr);
	else if (curr->type == BRACKET)
		ret = check_bracket(curr);
	return (ret);
}

int	check_syntax(t_info *info)
{
	t_dlist	*curr;
	int		ret;

	curr = info->dlist;
	init_syntax(info);
	ret = 1;
	if (curr->type == LINE || curr->type == PIPE)
		return (put_syntaxerr_msg(curr->token));
	while (curr->next)
	{
		ret = check_syntax_opt(curr);
		if (!ret)
			break ;
		curr = curr->next;
	}
	if (ret)
		ret = check_last(curr);
	return (ret);
}
