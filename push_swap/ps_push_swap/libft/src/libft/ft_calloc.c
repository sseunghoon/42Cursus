/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:46:30 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (p == NULL)
		return (0);
	ft_memset(p, 0, count * size);
	return (p);
}
