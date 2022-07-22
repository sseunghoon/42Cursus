/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:21:59 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/01 14:33:38 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*(str + length))
		length++;
	return (length);
}

void	ft_strcat(char *s1, char *s2)
{
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
}

char	*ft_malloc_answer(int answer_length)
{
	char	*answer;
	int		i;

	answer = (char *)malloc(sizeof(char) * (answer_length + 1));
	i = 0;
	while (i <= answer_length)
		answer[i++] = '\0';
	return (answer);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*answer;
	int		answer_length;
	int		i;

	if (size <= 0)
	{
		answer = (char *)malloc(sizeof(char));
		return (answer);
	}
	answer_length = 0;
	i = 0;
	while (i < size)
		answer_length += ft_strlen(*(strs + i++));
	answer_length += ft_strlen(sep) * (size - 1);
	answer = ft_malloc_answer(answer_length);
	ft_strcat(answer, *strs++);
	i = 1;
	while (i++ < size)
	{
		ft_strcat(answer, sep);
		ft_strcat(answer, *strs);
		strs++;
	}
	answer[answer_length] = '\0';
	return (answer);
}
