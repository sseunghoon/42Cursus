/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:42:21 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 18:42:23 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	size;

	index = 0;
	size = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (size);
	while (src[index] != '\0' && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (size);
}
