/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:44:10 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 18:44:25 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	chr;
	size_t	i;

	last = (char *)s;
	chr = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == chr)
			return (last + i);
		i--;
	}
	if (last[i] == chr)
		return (last);
	return (0);
}
