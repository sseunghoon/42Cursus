/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_redir_inout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/16 15:21:59 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	flag_on_redirin(t_info *info, t_tree *myself, int *r_fd)
{
	if (*r_fd != -1)
	{
		dup2(*r_fd, STDIN_FILENO);
		close(*r_fd);
	}
	else
		info->err_flag = 1;
}

int	redir_input(t_info *info, t_tree *myself)
{
	char	*file_name;
	int		r_fd;
	int		left;

	file_name = myself->dlist->token;
	while (*file_name == '<')
		file_name++;
	r_fd = open(file_name, O_RDONLY);
	if (r_fd == -1 && (!myself->left_child
			|| myself->left_child->dlist->type == WORD))
		return (puterr_exit_code(file_name, 0, 0));
	if (!info->redir_in_flag && ++info->redir_in_flag)
		flag_on_redirin(info, myself, &r_fd);
	left = execute(info, myself->left_child);
	if (info->redir_cnt == 1)
		first_redir(info);
	if (left)
		return (left);
	if (r_fd == -1)
		return (puterr_exit_code(file_name, 0, 0));
	return (0);
}

int	redir_output(t_info *info, t_tree *myself)
{
	char	*file_name;
	int		r_fd;
	int		left;

	file_name = myself->dlist->token;
	while (*file_name == '>')
		file_name++;
	if (myself->dlist->token[1] == '>')
		r_fd = open(file_name, O_CREAT | O_APPEND | O_RDWR, 0644);
	else
		r_fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (!info->redir_out_flag && ++info->redir_out_flag)
		dup2(r_fd, STDOUT_FILENO);
	close(r_fd);
	left = execute(info, myself->left_child);
	if (info->redir_cnt == 1)
		first_redir(info);
	if (left)
	{
		if (left != 127 && left != 130 && left != 131)
			unlink(file_name);
		return (left);
	}
	return (0);
}
