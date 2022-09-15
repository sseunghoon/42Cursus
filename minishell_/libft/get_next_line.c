/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:06:40 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/15 09:17:33 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_nl_join(char *last, char *new, char c)
{
	size_t	len1;
	size_t	len2;
	size_t	size;
	char	*str_join;

	if (!new)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (last && last[len1])
		len1++;
	while (new[len2] != c)
		len2++;
	if (c != '\0')
		len2 += 1;
	size = len1 + len2;
	str_join = malloc(sizeof(char) * (size + 1));
	if (!str_join)
		return (NULL);
	while (len1--)
		*(str_join++) = *(last++);
	while (len2--)
		*(str_join++) = *(new++);
	*str_join = '\0';
	return (str_join - size);
}

static int	make_rest(char *main, char **rest)
{
	char	*temp;
	char	*start;

	if (main == NULL)
	{
		start = ft_strchr(*rest, '\n');
		temp = ft_strdup(start + 1);
		if (*rest != NULL)
			free(*rest);
		*rest = temp;
	}
	else
	{
		start = ft_strchr(main, '\n');
		temp = ft_strdup(start + 1);
		if (*rest != NULL)
			free(*rest);
		*rest = temp;
	}
	return (0);
}

static int	make_return(char *buff, char **ret_str)
{
	char	*last_str;

	if (buff == NULL && *ret_str == NULL)
		return (0);
	last_str = *ret_str;
	if (ft_strchr(buff, '\n') != NULL)
	{
		*ret_str = ft_str_nl_join(last_str, buff, '\n');
		free(last_str);
		return (1);
	}
	else
	{
		*ret_str = ft_str_nl_join(last_str, buff, '\0');
		free(last_str);
		return (0);
	}
}

static int	read_file(char *main, char **rest, char **ret_str, int fd)
{
	int		read_check;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, main, 1024);
		if (read_check <= 0)
			return (-1);
		if (read_check <= 1024)
			main[read_check] = '\0';
		if (make_return(main, ret_str) && !make_rest(main, rest))
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret_str;
	char		*main;

	if (fd < 0)
		return (NULL);
	ret_str = NULL;
	if (make_return(save, &ret_str) && !make_rest(NULL, &save))
		return (ret_str);
	main = malloc(sizeof(char) * (1024 + 1));
	if (!main)
		return (NULL);
	if (read_file(main, &save, &ret_str, fd))
	{
		free(save);
		save = NULL;
	}
	free(main);
	return (ret_str);
}
