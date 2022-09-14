#include "../minishell.h"

extern int	g_exit_code;

int	execute_line(t_info *info, t_tree *myself)
{
	int	left;
	int	right;

	left = execute(info, myself->left_child);
	if (myself->dlist->token[0] == '&' && !left)
		right = execute(info, myself->right_child);
	else if (myself->dlist->token[0] == '|' && left)
		right = execute(info, myself->right_child);
	else
		return (left);
	return (right);
}

char	*fix_bracket(char *token)
{
	char	*fixed;
	char	tmp;
	int		len;

	fixed = ft_strdup(token);
	len = ft_strlen(fixed);
	ft_strlcpy(&fixed[0], &fixed[1], len);
	len -= 2;
	tmp = fixed[len - 1];
	ft_strlcpy(&fixed[len - 1], &fixed[len], 2);
	len--;
	fixed[len] = tmp;
	return (fixed);
}

int	execute_bracket(t_info *info, t_tree *myself)
{
	char	*str;
	t_info	infoo;
	t_ftool	tool;

	str = fix_bracket(myself->dlist->token);
	tool.pid = fork();
	if (!tool.pid)
	{
		ft_memset(&infoo, 0, sizeof(t_info));
		infoo.env = info->env;
		if (before_cmd(str, &infoo))
			exit(g_exit_code);
		if (after_cmd(str, &infoo))
			exit(g_exit_code);
		infoo.root = make_tree(NULL, infoo.dlist);
		expand(&infoo, infoo.root);
		if (here_doc(&infoo, infoo.root) && !close_main(&infoo, str))
			exit(g_exit_code);
		g_exit_code = execute(&infoo, infoo.root);
		close_main(&infoo, str);
		exit(g_exit_code);
	}
	waitpid(tool.pid, &tool.status, 0);
	free(str);
	return (WEXITSTATUS(tool.status));
}

int	execute(t_info *info, t_tree *myself)
{
	if (!myself)
		return (0);
	if (myself->dlist->type == LINE)
		return (execute_line(info, myself));
	if (myself->dlist->type == PIPE)
		return (execute_pipe(info, myself));
	if (myself->dlist->type == REDIR)
		return (execute_redir(info, myself));
	if (myself->dlist->type == WORD)
		return (execute_word(info, myself));
	if (myself->dlist->type == BRACKET)
		return (execute_bracket(info, myself));
	return (0);
}
