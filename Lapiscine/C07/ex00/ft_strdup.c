/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:21:29 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/01 12:52:26 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	char	*tmp;
	int		length;

	length = 0;
	while (*(src + length))
		length++;
	cpy = (char *)malloc(sizeof(char) * (length + 1));
	tmp = cpy;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (cpy);
}
