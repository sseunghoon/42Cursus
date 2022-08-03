/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:08:01 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 17:24:28 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	ft_read_process(char **buffers, int fd, char **result)
{
	int			read_val;

	read_val = read(fd, buffers[fd], BUFFER_SIZE);
	if (read_val == 0)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
	}
	if (read_val == -1)
	{
		if (buffers[fd])
		{
			free(buffers[fd]);
			buffers[fd] = NULL;
		}
		if (*result)
		{
			free(*result);
			*result = NULL;
		}
		return (-1);
	}
	if (read_val != 0)
		buffers[fd][read_val] = '\0';
	return (read_val);
}

char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	int			flag;
	int			read_val;
	char		*result;

	flag = 1;
	read_val = 1;
	result = NULL;
	while (flag > 0 && read_val > 0 && fd >= 0)
	{
		if (buffers[fd])
			flag = ft_find_nl(buffers, fd, &result);
		if (flag == 1)
		{
			if (ft_malloc_buff(buffers, fd) == -1)
			{
				flag = -1;
				break ;
			}
			read_val = ft_read_process(buffers, fd, &result);
		}
	}
	if (flag == -1)
		ft_free_all(buffers, &result);
	return (result);
}
