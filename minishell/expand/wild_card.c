#include "../minishell.h"

int	check_wildcard(t_dlist *curr, char quote, int i, int w_cnt)
{
	char	*tmp;

	tmp = curr->token;
	while (tmp[i])
	{
		if (tmp[i] == '\'' || tmp[i] == '\"')
		{
			quote = tmp[i++];
			while (tmp[i] != quote)
				i++;
		}
		else if (tmp[i] == '*')
			w_cnt++;
		i++;
	}
	if (!w_cnt)
		return (0);
	return (1);
}

void	split_dir(char *path, char **curr, char **next)
{
	int	i;
	int	last_dir_idx;

	i = 0;
	last_dir_idx = 0;
	while (!ft_strncmp("./", path, 2))
		ft_strlcpy(path, &path[2], ft_strlen(path));
	while (path[i] && path[i] != '/')
		i++;
	if (path[i] != '/')
	{
		*curr = ft_strdup(path);
		*next = NULL;
	}
	else
	{
		*curr = ft_strndup(path, i);
		*next = ft_strdup(&path[i]);
	}
}

t_dlist	*change_to_word(char *curr, char *next, int com_flag)
{
	DIR				*d_info;
	struct dirent	*d_entry;
	t_info			tmp_info;
	char			*ret;

	d_info = opendir("./");
	d_entry = readdir(d_info);
	tmp_info.dlist = NULL;
	while (d_entry)
	{
		if (((com_flag && d_entry->d_name[0] == '.')
				|| ((!com_flag && d_entry->d_name[0] != '.')
					&& (ft_strncmp(d_entry->d_name, ".", 2)
						&& ft_strncmp(d_entry->d_name, "..", 3))))
			&& filter_wildcard(curr, d_entry->d_name, -1, 0)
			&& ((d_entry->d_type == 8 && !next) || (d_entry->d_type == 4)))
		{
			ret = ft_strjoin(d_entry->d_name, next);
			add_list(&tmp_info.dlist, ret);
		}
		d_entry = readdir(d_info);
	}
	closedir(d_info);
	return (tmp_info.dlist);
}		

int	wildcard(t_dlist **now)
{
	char	*curr_path;
	char	*next_path;
	t_dlist	*new_list;
	int		dot_flag;

	if (!check_wildcard(*now, 0, 0, 0))
		return (0);
	split_dir((*now)->token, &curr_path, &next_path);
	dot_flag = 0;
	if (curr_path[0] == '.')
		dot_flag = 1;
	new_list = change_to_word(curr_path, next_path, dot_flag);
	free(curr_path);
	if (next_path)
		free(next_path);
	if (new_list && set_list(*now, new_list))
		*now = new_list;
	return (0);
}
