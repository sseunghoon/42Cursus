/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:31:08 by kyhan             #+#    #+#             */
/*   Updated: 2022/03/15 20:38:25 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put(char *str, int len, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		str[i] = 48;
	while (n != 0)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (10);
		else
			n = -n;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		minus;
	int		len;

	minus = (n < 0);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + minus + 1));
	if (str == 0)
		return (NULL);
	str[len + minus] = '\0';
	if (n == -2147483648)
	{
		str[10] = '8';
		n = 214748364;
		str[0] = '-';
		len--;
	}
	else if (minus == 1)
	{
		str[0] = '-';
		n = -n;
	}
	ft_put(&str[minus], len, n);
	return (&str[0]);
}
