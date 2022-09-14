/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:33:49 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 18:36:00 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		a;

	ptr = (const unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*ptr == a)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
