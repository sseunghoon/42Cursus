/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:08:01 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:46:06 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	ft_malloc_buff(char **buffers, int fd)
{
	buffers[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffers[fd] == NULL)
		return (-1);
	return (0);
}

char	*ft_buffncat(char **result, char *buff, int n, int ft_buff_len)
{
	int		i;
	int		result_len;
	char	*p;

	result_len = 0;
	while (*result && (*result)[result_len])
		result_len++;
	if (n == -1)
		n = ft_buff_len;
	p = malloc(sizeof(char) * (result_len + n + 1));
	if (p == NULL)
		return (0);
	i = -1;
	while (++i < result_len + n)
	{
		if (i < result_len)
			p[i] = (*result)[i];
		else
			p[i] = buff[i - result_len];
	}
	p[i] = '\0';
	if (*result)
		free(*result);
	*result = p;
	return (*result);
}

int	ft_find_nl(char **buffers, int fd, char **result)
{
	char	*buff;
	int		nl;
	int		flag;
	int		buff_len;

	buff = buffers[fd];
	nl = -2;
	buff_len = 0;
	while (buff[buff_len])
	{
		if (buff[buff_len] == '\n' && nl == -2)
			nl = buff_len;
		buff_len++;
	}
	flag = 0;
	if (nl == -2)
		flag = 1;
	if (ft_buffncat(result, buff, nl + 1, buff_len) != NULL && \
		ft_realloc_buff(buffers, fd, nl + 1, buff_len) != -1)
		return (flag);
	return (-1);
}

int	ft_realloc_buff(char **buffers, int fd, int n, int buff_len)
{
	int		i;
	char	*new_buff;

	if (n == buff_len || n == -1)
	{
		if (buffers[fd])
			free(buffers[fd]);
		buffers[fd] = NULL;
		return (0);
	}
	new_buff = malloc(sizeof(char) * (buff_len - n + 1));
	if (new_buff == NULL)
		return (-1);
	i = 0;
	while (i < buff_len - n)
	{
		new_buff[i] = buffers[fd][n + i];
		i++;
	}
	new_buff[i] = '\0';
	free(buffers[fd]);
	buffers[fd] = new_buff;
	return (0);
}

void	ft_free_all(char **buffers, char **result)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (buffers[i])
		{
			free(buffers[i]);
			buffers[i] = NULL;
		}
		i++;
	}
	if (*result)
	{
		free(*result);
		*result = NULL;
	}
}
