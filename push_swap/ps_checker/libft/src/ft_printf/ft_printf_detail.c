/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:38:27 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:33:53 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_char(va_list ap, t_options *opt, int *cnt, const char c)
{
	char	ch;

	if (c == '%')
	{
		ch = '%';
	}
	else
		ch = va_arg(ap, int);
	if (opt->flags.minus == OFF)
		put_space_zero(opt->flags.zero, opt->width - 1, cnt);
	write(1, &ch, 1);
	*cnt += 1;
	if (opt->flags.minus == ON)
		put_space_zero(opt->flags.zero, opt->width - 1, cnt);
	return (1);
}

int	ft_print_str(va_list ap, t_options *opt, int *cnt)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (opt->prec != -1)
		len = ft_min(len, opt->prec);
	if (opt->flags.minus == OFF)
		put_space_zero(opt->flags.zero, opt->width - len, cnt);
	write(1, str, len);
	*cnt += len;
	if (opt->flags.minus == ON)
		put_space_zero(opt->flags.zero, opt->width - len, cnt);
	return (1);
}

void	ft_print_sign(t_options *opt, t_strinfo strinfo, int *cnt)
{
	if (strinfo.sign == SIGN_MINUS)
	{
		write(1, "-", 1);
		*cnt += 1;
	}
	if (strinfo.sign == SIGN_PLUS && \
		(opt->flags.blank == ON || opt->flags.plus == ON))
	{
		if (opt->flags.blank == ON)
			ft_putchar_fd(' ', 1);
		if (opt->flags.plus == ON)
			ft_putchar_fd('+', 1);
		(*cnt)++;
	}
	if (strinfo.sign == SIGN_L_HEX)
	{
		(*cnt) += 2;
		write(1, "0x", 2);
	}
	if (strinfo.sign == SIGN_U_HEX)
	{
		(*cnt) += 2;
		write(1, "0X", 2);
	}
}

int	ft_print_nbr(va_list ap, t_options *opt, int *cnt, const char c)
{
	t_strinfo	strinfo;
	int			sign_len;

	if (ft_get_diuinfo(&strinfo, ap, c) == -1)
		return (-1);
	sign_len = 0;
	if (opt->flags.blank == ON || opt->flags.plus == ON || strinfo.sign == -1)
		sign_len = 1;
	check_both_zero(&strinfo, opt);
	if (opt->flags.zero == ON)
		ft_print_sign(opt, strinfo, cnt);
	if (opt->flags.minus == OFF)
		put_space_zero(opt->flags.zero, opt->width - \
							ft_max(strinfo.len, opt->prec) - sign_len, cnt);
	if (opt->flags.zero == OFF)
		ft_print_sign(opt, strinfo, cnt);
	put_space_zero(ON, opt->prec - strinfo.len, cnt);
	*cnt += write(1, strinfo.str, strinfo.len);
	if (opt->flags.minus == ON)
		put_space_zero(opt->flags.zero, opt->width - \
							ft_max(strinfo.len, opt->prec) - sign_len, cnt);
	free(strinfo.str);
	return (1);
}

int	ft_print_pxx(va_list ap, t_options *opt, int *cnt, const char c)
{
	t_strinfo	strinfo;
	int			hash_len;

	hash_len = 0;
	if (ft_get_pxxinfo(&strinfo, ap, c) == -1)
		return (-1);
	if (c == 'p' || (opt->flags.hash == ON && *(strinfo.str) != '0'))
		hash_len = 2;
	check_both_zero(&strinfo, opt);
	if (opt->flags.zero == ON && \
	((opt->flags.hash == ON && strinfo.str[0] != '0') || c == 'p'))
		ft_print_sign(opt, strinfo, cnt);
	if (opt->flags.minus == OFF)
		put_space_zero(opt->flags.zero, opt->width - \
						ft_max(strinfo.len, opt->prec) - hash_len, cnt);
	if (opt->flags.zero == OFF && \
	((opt->flags.hash == ON && strinfo.str[0] != '0') || c == 'p'))
		ft_print_sign(opt, strinfo, cnt);
	put_space_zero(ON, opt->prec - strinfo.len, cnt);
	*cnt += write(1, strinfo.str, strinfo.len);
	if (opt->flags.minus == ON)
		put_space_zero(opt->flags.zero, opt->width - \
						ft_max(strinfo.len, opt->prec) - hash_len, cnt);
	free(strinfo.str);
	return (1);
}
