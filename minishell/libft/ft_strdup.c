/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:39:53 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 18:40:11 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	s1len;
	size_t	i;

	i = 0;
	s1len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s1len + 1));
	if (dup == 0)
		return (0);
	while (i < s1len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
