/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:50:09 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 20:42:16 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		minus;
	size_t	i;

	i = 0;
	res = 0;
	minus = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && (str[i] != '\0'))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (res > 2147483647 && minus == 1)
			return (-1);
		if (res > 2147483648 && minus == -1)
			return (0);
	}
	return (minus * res);
}
