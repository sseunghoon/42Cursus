/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:06:40 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/05 11:28:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	make_rest(char *main, char **rest)
{
	char	*temp;
	char	*start;

	if (main == NULL)
	{
		start = ft_strchrr(*rest, '\n');
		temp = ft_strdupp(start);
		if (*rest != NULL)
			free(*rest);
		*rest = temp;
	}
	else
	{
		start = ft_strchrr(main, '\n');
		temp = ft_strdupp(start);
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
	if (ft_strchrr(buff, '\n') != NULL)
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
		read_check = read(fd, main, BUFFER_SIZE);
		if (read_check <= 0)
			return (-1);
		if (read_check <= BUFFER_SIZE)
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

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ret_str = NULL;
	if (make_return(save, &ret_str) && !make_rest(NULL, &save))
		return (ret_str);
	main = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
