/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:02:42 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/01 12:53:35 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	*tmp;

	if (min >= max)
		return (0);
	p = (int *)malloc(sizeof(int) * (max - min));
	tmp = p;
	while (min < max)
	{
		*tmp++ = min++;
	}
	return (p);
}
