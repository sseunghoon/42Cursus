/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:46:55 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 16:06:05 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	**ft_malloc_result1(char const *str, char c)
{
	int		word_cnt;
	int		is_new;
	int		i;
	char	**result;

	word_cnt = 0;
	i = -1;
	is_new = 1;
	while (str[++i])
	{
		if (str[i] != c && is_new == 1)
		{
			is_new = 0;
			word_cnt++;
		}
		if (str[i] == c && is_new == 0)
			is_new = 1;
	}
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (result == NULL)
	{
		return (0);
	}
	result[word_cnt] = 0;
	return (result);
}

static char	*ft_malloc_result2(char **result, \
char const *str, int wi_st_isn[], int end)
{
	int		j;
	char	*p;

	p = (char *)malloc(end - wi_st_isn[1] + 1);
	if (p == NULL)
	{
		wi_st_isn[0]--;
		while (wi_st_isn[0] > 0)
		{
			free(result[wi_st_isn[0]]);
			wi_st_isn[0]--;
		}
		free(result);
		return (0);
	}
	j = 0;
	while (wi_st_isn[1] < end)
		p[j++] = str[wi_st_isn[1]++];
	p[j] = '\0';
	return (p);
}

static int	ft_mini(char const *s, char c, int wi_st_isn[], char **result)
{
	int	i;
	int	len;

	i = -1;
	len = (int) ft_strlen(s);
	while (++i < len + 1)
	{
		if ((i == len && wi_st_isn[2] == 0) || (s[i] == c && wi_st_isn[2] == 0))
		{
			result[wi_st_isn[0]] = ft_malloc_result2(result, s, wi_st_isn, i);
			if (result[wi_st_isn[0]] == NULL)
				return (-1);
			wi_st_isn[0] += 1;
			wi_st_isn[2] = 1;
		}
		else if (s[i] != c && wi_st_isn[2] == 1)
		{
			wi_st_isn[1] = i;
			wi_st_isn[2] = 0;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		wi_st_isn[3];
	char	**result;

	wi_st_isn[0] = 0;
	wi_st_isn[2] = 1;
	result = ft_malloc_result1(s, c);
	if (result == NULL)
		return (0);
	if (ft_mini(s, c, wi_st_isn, result) == -1)
		return (0);
	return (result);
}
