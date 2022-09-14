#include "../minishell.h"

int	set_list(t_dlist *curr, t_dlist *new_list)
{
	t_dlist	*temp;

	temp = new_list;
	temp->type = WORD;
	if (curr->prev)
	{
		temp->prev = curr->prev;
		curr->prev->next = temp;
	}
	while (temp->next)
	{
		temp = temp->next;
		temp->type = WORD;
	}
	if (curr->next)
	{
		temp->next = curr->next;
		curr->next->prev = temp;
	}
	return (1);
}

char	*ft_str_rep_wildcard(char *d_name, char *next_path)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	while (next_path[i] && next_path[i] != '/')
		i++;
	i = i + 1;
	tmp = ft_strdup(&next_path[i]);
	ret = ft_strjoin(d_name, tmp);
	free(tmp);
	return (ret);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == 0)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	wild_free(char **split, char *tmp)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(tmp);
	return (1);
}

int	filter_wildcard(char *wc, char *str, int i, int j)
{
	char	**split;
	char	*tmp;
	int		last;
	int		str_len;

	str_len = ft_strlen(str);
	last = ft_strlen(wc);
	while (wc[++i] != '*')
		if (wc[i] != str[i])
			return (0);
	while (wc[--last] != '*')
		if (wc[last] != str[--str_len])
			return (0);
	tmp = ft_strndup(&wc[i], last - i + 1);
	split = ft_split(tmp, '*');
	while (split[j] && str[i])
	{
		if (!ft_strncmp(split[j], &str[i], ft_strlen(split[j])))
			i += ft_strlen(split[j++]);
		i++;
	}
	if (!split[j] || (wc[0] == '*' && !wc[1]))
		return (wild_free(split, tmp));
	return (wild_free(split, tmp) - 1);
}
