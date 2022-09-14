/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:45:55 by kyhan             #+#    #+#             */
/*   Updated: 2022/04/12 08:24:40 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nid, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*nid == '\0')
	{
		return ((char *)hay);
	}
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == nid[j] && (i + j) < len)
		{
			j++;
			if (nid[j] == '\0')
			{
				return ((char *)(&hay[i]));
			}
		}
		i++;
	}
	return (0);
}
