/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 16:07:51 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_strcut(char const *s1, char const *set, \
						int *start, int *end)
{
	int	len;
	int	flag;

	*start = 0;
	*end = 0;
	flag = 0;
	len = 0;
	while (s1[len])
	{
		if (!ft_strchr(set, s1[len]) && flag == 0)
		{
			*start = len;
			flag = 1;
		}
		if (!ft_strchr(set, s1[len]))
			*end = len;
		len++;
	}
	return (flag);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		flag;
	char	*p;

	flag = ft_strcut(s1, set, &start, &end);
	p = (char *)malloc(sizeof(char) * (end - start + flag + 1));
	if (p == NULL)
		return (0);
	p[end - start + flag] = '\0';
	while (start <= end && flag == 1)
	{
		p[end - start] = s1[end];
		end--;
	}
	return (p);
}
