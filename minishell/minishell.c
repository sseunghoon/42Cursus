#include "minishell.h"

int	g_exit_code;

int	before_cmd(char *str, t_info *info)
{
	if (!str)
	{
		printf("exit\n");
		exit(0);
	}
	if (space_check(str) == TRUE)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	after_cmd(char *str, t_info *info)
{
	if (!input_check(str))
	{
		free(str);
		return (1);
	}
	if (!lexer(str, info))
	{
		free(str);
		delete_dlist(info->dlist);
		return (1);
	}
	return (0);
}

int	close_main(t_info *info, char *str)
{
	char	*file_name;
	char	*file_num;

	free(str);
	free_tree(info->root);
	while (info->hd_cnt)
	{
		file_num = ft_itoa(info->hd_cnt);
		file_name = ft_strjoin(".2Pj-9C6-v9X-g47", file_num);
		unlink(file_name);
		free(file_num);
		free(file_name);
		info->hd_cnt--;
	}
	return (0);
}

int	main(void)
{
	char	*str;
	t_info	info;

	init_env(&info);
	set_terminal();
	while (1)
	{
		init_info(&info);
		set_signal_handler(0);
		str = readline("morningshell$ ");
		if (before_cmd(str, &info))
			continue ;
		add_history(str);
		if (after_cmd(str, &info))
			continue ;
		info.root = make_tree(NULL, info.dlist);
		expand(&info, info.root);
		set_signal_handler(1);
		if (here_doc(&info, info.root) && !close_main(&info, str))
			continue ;
		g_exit_code = execute(&info, info.root);
		close_main(&info, str);
	}
	return (0);
}
