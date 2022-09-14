/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:30:54 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 20:30:58 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	is_sep(char const s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

int	count_words(char const *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && is_sep(*str, c))
			str++;
		if (*str && !is_sep(*str, c))
		{
			cnt++;
			while (*str && !is_sep(*str, c))
				str++;
		}
	}
	return (cnt);
}

char	*malloc_word(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (res == 0)
		return (NULL);
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			res[i++] = malloc_word(s, c);
			if (res == 0)
				return (freeall(res));
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	res[i] = 0;
	return (res);
}
