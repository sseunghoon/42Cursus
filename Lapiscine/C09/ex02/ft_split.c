/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:46:55 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/04 12:56:26 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char ch, char *charset)
{
	while (*charset)
	{
		if (ch == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	**ft_malloc_result1(char *str, char *charset)
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
		if (ft_is_sep(str[i], charset) == 0 && is_new == 1)
		{
			is_new = 0;
			word_cnt++;
		}
		if (ft_is_sep(str[i], charset) == 1 && is_new == 0)
			is_new = 1;
	}
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	result[word_cnt] = 0;
	return (result);
}

void	ft_malloc_result2(char **result, char *str, int wi_st_isn[], int end)
{
	int	j;

	j = 0;
	result[wi_st_isn[0]] = (char *)malloc(end - wi_st_isn[1] + 1);
	while (wi_st_isn[1] < end)
		result[wi_st_isn[0]][j++] = str[wi_st_isn[1]++];
	result[wi_st_isn[0]][j] = '\0';
	wi_st_isn[0] += 1;
	wi_st_isn[2] = 1;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		wi_st_isn[3];
	char	**result;

	wi_st_isn[0] = 0;
	wi_st_isn[2] = 1;
	result = ft_malloc_result1(str, charset);
	i = -1;
	while (++i < ft_strlen2(str) + 1)
	{
		if (i == ft_strlen2(str) && wi_st_isn[2] == 0)
			ft_malloc_result2(result, str, wi_st_isn, i);
		else if (ft_is_sep(str[i], charset) == 0 && wi_st_isn[2] == 1)
		{
			wi_st_isn[1] = i;
			wi_st_isn[2] = 0;
		}
		else if (ft_is_sep(str[i], charset) == 1 && wi_st_isn[2] == 0)
			ft_malloc_result2(result, str, wi_st_isn, i);
	}
	return (result);
}
