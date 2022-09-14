#include "../minishell.h"

extern int	g_exit_code;

void	first_redir(t_info *info)
{
	close(info->tmp_fd);
	dup2(info->in_fd, STDIN_FILENO);
	dup2(info->out_fd, STDOUT_FILENO);
	close(info->in_fd);
	close(info->out_fd);
	info->redir_out_flag = 0;
	info->redir_in_flag = 0;
	info->tmp_fd = 0;
}

t_tree	*move_hierarchy(t_tree *myself, int flag)
{
	t_tree	*target;

	if (flag == VERTICAL)
	{
		target = myself->left_child->right_child;
		if (target == NULL)
		{
			myself->left_child->right_child = myself->right_child;
			myself->right_child = 0;
			return (NULL);
		}
	}
	else
	{
		target = myself->left_child;
		if (target == NULL)
		{
			myself->left_child = myself->right_child;
			myself->right_child = 0;
			return (NULL);
		}
	}
	return (target);
}

void	append_list(t_tree *myself, int flag)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_tree	*target;

	if (!myself->right_child)
		return ;
	tmp1 = myself->right_child->dlist;
	target = move_hierarchy(myself, flag);
	if (!target)
		return ;
	tmp2 = target->dlist;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	free(myself->right_child);
	myself->right_child = 0;
}

void	make_friends(t_info *info, t_tree *myself)
{
	if (myself->left_child && myself->left_child->dlist->type != WORD)
	{
		append_list(myself, VERTICAL);
		make_friends(info, myself->left_child);
	}
	else
		append_list(myself, HORIZONTAL);
}

int	execute_redir(t_info *info, t_tree *myself)
{
	int	ret;

	info->redir_cnt++;
	if (info->redir_cnt == 1)
	{
		info->in_fd = dup(STDIN_FILENO);
		info->out_fd = dup(STDOUT_FILENO);
		make_friends(info, myself);
	}
	if (myself->dlist->token[0] == '<' && myself->dlist->token[1] != '<')
		ret = redir_input(info, myself);
	else if (myself->dlist->token[0] == '>')
		ret = redir_output(info, myself);
	if (!ret && info->redir_cnt == 1)
		first_redir(info);
	info->redir_cnt--;
	return (ret);
}
