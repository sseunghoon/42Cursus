/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:04:55 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:33:57 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_update_flag(t_options *option, const char c)
{
	if (c == '-')
	{
		option->flags.minus = ON;
		option->flags.zero = OFF;
	}
	if (c == '#')
		option->flags.hash = ON;
	if (c == ' ')
	{
		if (option->flags.plus != ON)
			option->flags.blank = ON;
	}
	if (c == '+')
	{
		option->flags.plus = ON;
		option->flags.blank = OFF;
	}
}

void	ft_update_width_preq(t_options *option, const char c)
{
	if (option->prec == -1)
	{
		if (option->width == -1)
			option->width = 0;
		option->width = option->width * 10 + c - '0';
	}
	else
		option->prec = option->prec * 10 + c - '0';
}

char	*ft_itoa_base(unsigned long long nbr, char *base, \
		unsigned long long base_length)
{
	unsigned long long	result_length;
	unsigned long long	tmp_nbr;
	unsigned long long	sign;
	char				*result;

	result_length = 0;
	sign = 1;
	if (nbr == 0)
		result_length = 1;
	tmp_nbr = nbr;
	while (tmp_nbr != 0)
	{
		tmp_nbr /= base_length;
		result_length++;
	}
	result = (char *)malloc(sizeof(char) * (result_length + 1));
	if (result == NULL)
		return (0);
	result[result_length] = '\0';
	while (result_length-- > 0)
	{
		result[result_length] = base[nbr % base_length * sign];
		nbr /= base_length;
	}
	return (result);
}

void	put_space_zero(t_switch flag, int len_space_zero, int *cnt)
{
	if (len_space_zero > 0)
		*cnt += len_space_zero;
	while (len_space_zero-- > 0)
	{
		if (flag == ON)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

void	check_both_zero(t_strinfo *strinfo, t_options *opt)
{
	if (*(strinfo->str) == '0' && opt->prec == 0)
		strinfo->len = 0;
}
