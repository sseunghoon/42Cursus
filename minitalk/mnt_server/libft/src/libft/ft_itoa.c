/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 16:11:52 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_ilen(int n)
{
	int	result_length;
	int	tmp_n;

	result_length = 1;
	if (n < 0)
		result_length++;
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
		return (NULL);
	}
	result[result_length] = '\0';
	while (result_length-- > 0)
	{
		result[result_length] = '0' + n % 10 * sign;
		n /= 10;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}
