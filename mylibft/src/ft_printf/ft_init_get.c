/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:19 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:33:50 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_init_option(t_options *options)
{
	options->flags.blank = OFF;
	options->flags.hash = OFF;
	options->flags.minus = OFF;
	options->flags.plus = OFF;
	options->flags.zero = OFF;
	options->width = -1;
	options->prec = -1;
}

void	ft_init_strinfo(t_strinfo *strinfo)
{
	strinfo->str = NULL;
	strinfo->len = 0;
	strinfo->sign = 1;
}

// itoa에서 할당 실패하면 -1 반환, 널가드 실행
int	ft_get_diuinfo(t_strinfo *strinfo, va_list ap, const char c)
{
	int				nbr;
	unsigned int	unbr;

	ft_init_strinfo(strinfo);
	if (c == 'd' || c == 'i')
	{
		nbr = va_arg(ap, int);
		if (nbr < 0)
			strinfo->sign = -1;
		strinfo->str = ft_itoa(nbr);
	}
	if (c == 'u')
	{
		unbr = va_arg(ap, unsigned int);
		strinfo->str = ft_itoa(unbr);
	}
	if (strinfo->str == NULL)
		return (-1);
	strinfo->len = ft_strlen(strinfo->str);
	return (0);
}

int	ft_get_pxxinfo(t_strinfo *strinfo, va_list ap, const char c)
{
	ft_init_strinfo(strinfo);
	if (c == 'p')
	{
		strinfo->str = ft_itoa_base((long long)va_arg(ap, void *), \
									"0123456789abcdef", 16);
		strinfo->sign = SIGN_L_HEX;
	}
	if (c == 'x')
	{
		strinfo->str = ft_itoa_base((long long)va_arg(ap, unsigned int), \
									"0123456789abcdef", 16);
		strinfo->sign = SIGN_L_HEX;
	}
	if (c == 'X')
	{
		strinfo->str = ft_itoa_base((long long)va_arg(ap, unsigned int), \
									"0123456789ABCDEF", 16);
		strinfo->sign = SIGN_U_HEX;
	}
	if (strinfo->str == NULL)
		return (-1);
	strinfo->len = ft_strlen(strinfo->str);
	return (0);
}
