#include "../minishell.h"

char	*get_path_cd(t_info *info, char *find)
{
	t_dlist	*curr;
	char	*ret;

	curr = info->env;
	while (curr && ft_strncmp(curr->token, find, 5))
		curr = curr->next;
	if (!curr)
		return (NULL);
	ret = curr->token;
	ret += ft_strlen(find);
	return (ret);
}

int	add_export(t_info *info, char *tmp)
{
	char		*env;
	t_dlist		*env_list;
	t_dlist		*prev_lst;

	env = ft_strjoin("OLDPWD=", tmp);
	prev_lst = create_list();
	env_list = create_list();
	env_list->token = env;
	prev_lst->next = env_list;
	export(info, prev_lst);
	free(env);
	free(prev_lst);
	free(env_list);
	free(tmp);
	return (0);
}

int	set_cd_minus(t_info *info, t_dlist *list)
{
	char	*tmp;
	char	*old_path;

	old_path = getcwd(NULL, 0);
	tmp = get_path_cd(info, "OLDPWD=");
	if (!tmp)
	{
		free(old_path);
		return (put_str_err(list, "OLDPWD not set"));
	}
	printf("%s\n", tmp);
	chdir(tmp);
	add_export(info, old_path);
	return (0);
}

int	cd(t_info *info, t_dlist *list)
{
	char	*tmp;
	char	*old_path;

	if (!list->next)
	{
		tmp = get_path_cd(info, "HOME=");
		if (!tmp)
			return (put_str_err(list, "HOME not set"));
		return (chdir(tmp));
	}
	if (list->next->next)
		return (put_str_err(list, "too many arguments"));
	if (list->next->token[0] == '-' && list->next->token[1] == '\0')
		return (set_cd_minus(info, list));
	old_path = getcwd(NULL, 0);
	if (chdir(list->next->token))
	{
		free(old_path);
		return (puterr_exit_code("cd", 0, 0));
	}
	add_export(info, old_path);
	return (0);
}
