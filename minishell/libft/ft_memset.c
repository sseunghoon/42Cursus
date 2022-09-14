/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:30:54 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 18:30:57 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)p;
	while (i < len)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)arr);
}
