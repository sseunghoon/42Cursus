/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:50:28 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/05 21:50:34 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>

void	*ft_copy(void *dest, void *src, int n)
{
	char	*dest_buf;
	char	*src_buf;
	int		i;

	dest_buf = dest;
	src_buf = src;
	i = 0;
	while (i < n)
	{
		dest_buf[i] = src_buf[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isprintable(char c)
{
	return (32 <= c && c < 127);
}

char	*ft_insert_char(char *dest, char src)
{
	*dest++ = src;
	return (dest);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
