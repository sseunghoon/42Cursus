/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/16 17:05:43 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_code;

int	ft_access(char *path)
{
	int	tmp_fd;

	tmp_fd = open(path, O_RDONLY);
	if (tmp_fd == -1)
		return (-1);
	close(tmp_fd);
	return (0);
}

char	*split_path(t_info *info, char *env, char *cmd)
{
	char	*path;
	char	**splited;
	char	*dir;
	int		i;

	i = 0;
	splited = ft_split(env, ':');
	while (splited[i])
	{
		dir = ft_strjoin(splited[i], "/");
		path = ft_strjoin(dir, cmd);
		free(dir);
		if (ft_access(path) > -1)
		{
			info->path_flag = 1;
			ft_free(splited);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(splited);
	return (cmd);
}

char	*get_path(t_info *info, char *cmd, char **env)
{
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (0);
	tmp = env[i];
	tmp += 5;
	path = split_path(info, tmp, cmd);
	return (path);
}

int	word_child(char **argv, char **env, char *path)
{
	DIR	*tmp;

	tmp = opendir(argv[0]);
	if (tmp)
	{
		closedir(tmp);
		exit(puterr_exit_code(argv[0], 0, 126));
	}
	if (!path && execve(argv[0], argv, env) == -1)
		exit(puterr_exit_code(argv[0], 0, 0));
	else if (execve(path, argv, env) == -1)
		exit(puterr_exit_code(argv[0], 0, 127));
	return (0);
}

int	execute_word(t_info *info, t_tree *myself)
{
	char	**argv;
	char	**env;
	char	*path;
	t_ftool	tool;

	if (info->err_flag)
		return (0);
	myself->dlist = get_first(myself->dlist);
	tool.status = built_in(info, myself);
	if (tool.status != -1)
		return (tool.status);
	argv = make_str_arr(myself->dlist);
	env = make_str_arr(info->env);
	path = get_path(info, argv[0], env);
	tool.pid = fork();
	if (!tool.pid)
		word_child(argv, env, path);
	waitpid(tool.pid, &tool.status, 0);
	if (info->path_flag && info->path_flag--)
		free(path);
	free(argv);
	free(env);
	if (g_exit_code == 130 || g_exit_code == 131)
		return (g_exit_code);
	return (WEXITSTATUS(tool.status));
}
