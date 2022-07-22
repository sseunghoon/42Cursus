/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:46:25 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/01 14:33:53 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_is_valid(char *base)
{
	char	*p;
	char	*tmp_base;

	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	p = base;
	while (*p)
	{
		if (*p == '+' || *p == '-' || *p == 32 || (*p >= 9 && *p <= 13))
			return (0);
		tmp_base = base;
		while (tmp_base < p)
		{
			if (*tmp_base == *p)
				return (0);
			tmp_base++;
		}
		p++;
	}
	return (p - base);
}

int	ft_is_included(char ch, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, int base_length)
{
	int	minus_cnt;
	int	result;

	minus_cnt = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_cnt++;
		str++;
	}
	while (*str)
	{
		if (ft_is_included(*str, base) == -1)
			break ;
		result = result * base_length + ft_is_included(*str++, base);
	}
	if (minus_cnt % 2)
		return (result * (-1));
	return (result);
}

char	*ft_itoa_base(long long nbr, char *base, \
		long long base_length, long long sign)
{
	long long	result_length;
	long long	tmp_nbr;
	char		*result;

	result_length = 0;
	if (nbr == 0)
		result_length = 1;
	tmp_nbr = nbr;
	while (tmp_nbr > 0)
	{
		tmp_nbr /= base_length;
		result_length++;
	}
	if (sign < 0)
		result_length++;
	result = (char *)malloc(sizeof(char) * (result_length + 1));
	result[result_length] = '\0';
	while (result_length-- > 0)
	{
		result[result_length] = base[nbr % base_length];
		nbr /= base_length;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	n;
	long long	base_length;
	char		*result;

	base_length = ft_is_valid(base_from);
	if (base_length == 0)
		return (0);
	n = ft_atoi_base(nbr, base_from, base_length);
	base_length = ft_is_valid(base_to);
	if (base_length == 0)
		return (0);
	if (n >= 0)
		result = ft_itoa_base(n, base_to, base_length, 1);
	else
		result = ft_itoa_base(n * (-1), base_to, base_length, -1);
	return (result);
}
