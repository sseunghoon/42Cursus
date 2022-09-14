/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: littley <littley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:25:16 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/01 11:23:08 by littley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchrr(char *s, int c)
{
	char	*temp;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	temp = s;
	while (temp[i] != (char)c && temp[i])
		i++;
	if ((char)c && !temp[i])
		return (NULL);
	else
		return (&s[i + 1]);
}

char	*ft_strdupp(char *s)
{
	char	*temp;
	int		i;
	int		size;

	if (!s[0])
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_str_nl_join(char *last, char *new, char c)
{
	size_t	len1;
	size_t	len2;
	size_t	size;
	char	*str_join;

	if (!new)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (last && last[len1])
		len1++;
	while (new[len2] != c)
		len2++;
	if (c != '\0')
		len2 += 1;
	size = len1 + len2;
	str_join = malloc(sizeof(char) * (size + 1));
	if (!str_join)
		return (NULL);
	while (len1--)
		*(str_join++) = *(last++);
	while (len2--)
		*(str_join++) = *(new++);
	*str_join = '\0';
	return (str_join - size);
}
