/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:31:50 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/13 15:49:32 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned const char *)src;
	if (!dst && !src)
		return (0);
	if (temp_dst <= temp_src)
	{
		while (len--)
			*(temp_dst++) = *(temp_src++);
	}
	else
	{
		temp_dst += (len - 1);
		temp_src += (len - 1);
		while (len--)
			*(temp_dst--) = *(temp_src--);
	}
	return (dst);
}
