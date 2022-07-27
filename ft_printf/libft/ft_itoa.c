/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/14 19:18:20 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(long long n)
{
	int			result_length;
	long long	tmp_n;

	result_length = 1;
	tmp_n = n;
	while (tmp_n >= 10 || tmp_n <= -10)
	{
		tmp_n /= 10;
		result_length++;
	}
	return (result_length);
}

char	*ft_itoa(long long n)
{
	int		result_length;
	int		sign;
	char	*result;

	sign = 1;
	if (n < 0)
		sign = -1;
	result_length = ft_ilen(n);
	result = (char *)malloc(sizeof(char) * (result_length + 1));
	if (result == NULL)
	{
		return (0);
	}
	result[result_length] = '\0';
	while (result_length-- > 0)
	{
		result[result_length] = '0' + n % 10 * sign;
		n /= 10;
	}
	return (result);
}
