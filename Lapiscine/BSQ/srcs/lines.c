/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:50:47 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/07 16:52:12 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>
#include <unistd.h>

int	read_lines(t_file_lines *self, int fd)
{
	char			buf[BUFFER_MAX];
	int				count;
	t_string_chain	*chain;

	count = -2;
	while (count != 0)
	{
		if (count == -1)
			return (FALSE);
		if (count > 0)
		{
			chain = chain_command(self, INSERT);
			chain->str = ft_malloc(count);
			ft_copy(chain->str, buf, count);
			chain->length = count;
		}
		count = read(fd, buf, sizeof(buf));
	}
	chain = self->head;
	chain_command(self, REMOVE_ALL);
	return (split_chain(self, chain));
}

t_string_chain	*chain_command(t_file_lines *self, t_chain_cmd cmd)
{
	t_string_chain	*chain;

	if (cmd == INSERT)
	{
		chain = ft_malloc(sizeof(*chain));
		if (self->tail)
			self->tail->next = chain;
		else
			self->head = chain;
		self->tail = chain;
		chain->str = NULL;
		chain->offset = 0;
		chain->length = 0;
		chain->next = NULL;
		return (chain);
	}
	else if (cmd == REMOVE_ALL)
	{
		self->head = NULL;
		self->tail = NULL;
	}
	return (NULL);
}

int	split_chain(t_file_lines *self, t_string_chain *temp)
{
	t_string_chain	*chain;
	unsigned int	len;
	unsigned int	i;

	chain = temp;
	len = 0;
	while (chain)
	{
		i = 0;
		while (i < chain->length)
		{
			if (chain->str[i] == '\n')
			{
				if (!create_chain(self, len))
					return (FALSE);
				len = 0;
			}
			else
				len++;
			i++;
		}
		chain = chain->next;
	}
	return (create_chain(self, len) && numbering_temp(self, temp));
}

int	create_chain(t_file_lines *self, unsigned int length)
{
	t_string_chain	*chain;
	unsigned int	size;
	unsigned int	i;

	chain = chain_command(self, INSERT);
	if (chain == NULL)
		return (FALSE);
	size = length + 1;
	chain->str = ft_malloc(sizeof(*chain->str) * size);
	chain->length = size;
	i = 0;
	while (i < chain->length)
		chain->str[i++] = '\0';
	return (TRUE);
}

int	numbering_temp(t_file_lines *self, t_string_chain *temp)
{
	t_string_chain	*chain;
	t_string_chain	*next;
	unsigned int	i;

	chain = self->head;
	while (temp)
	{
		i = 0;
		while (i < temp->length)
		{
			if (temp->str[i] == '\n')
				chain = chain->next;
			else
				chain->str[chain->offset++] = temp->str[i];
			i++;
		}
		free(temp->str);
		next = temp->next;
		free(temp);
		temp = next;
	}
	return (TRUE);
}
