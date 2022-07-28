/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:08:16 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 15:34:00 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print(va_list ap, t_options *option, const char c, int *cnt)
{
	int	len;

	len = 0;
	if (c == '%' || c == 'c')
		return (ft_print_char(ap, option, cnt, c));
	if (c == 's')
		return (ft_print_str(ap, option, cnt));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_nbr(ap, option, cnt, c));
	if (c == 'p' || c == 'x' || c == 'X')
		return (ft_print_pxx(ap, option, cnt, c));
	return (0);
}

int	classify_form(va_list ap, t_options *option, const char c, int *cnt)
{
	if (c == '-' || c == '#' || c == ' ' || c == '+')
		ft_update_flag(option, c);
	else if (c == '0' && option->prec == -1 && option->width == -1)
	{
		if (option->flags.minus != ON)
			option->flags.zero = ON;
	}
	else if ('0' <= c && c <= '9')
		ft_update_width_preq(option, c);
	else if (c == '.')
	{
		option->prec = 0;
		option->flags.zero = OFF;
	}
	else
		return (ft_print(ap, option, c, cnt));
	return (0);
}

void	ft_put_non_form(const char c, int *is_form_spec, int *cnt)
{
	if (c == '%')
		*is_form_spec = FORMAT_SPECIFIER;
	else
	{
		write(1, &c, 1);
		(*cnt)++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_initial_var	init_var;
	int				ck;
	va_list			ap;

	va_start(ap, format);
	ft_init_var(&init_var);
	while (*format)
	{
		if (init_var.is_form_spec == FORMAT_SPECIFIER)
		{
			ck = classify_form(ap, &(init_var.opt), *format, &(init_var.cnt));
			if (ck == 1)
			{
				ft_init_option(&(init_var.opt));
				init_var.is_form_spec = NON_FORMAT_SPECIFIER;
			}
			if (ck == -1)
				return (-1);
		}
		else
			ft_put_non_form(*format, &(init_var.is_form_spec), &(init_var.cnt));
		format++;
	}
	va_end(ap);
	return (init_var.cnt);
}

void	ft_init_var(t_initial_var *initial_var)
{
	initial_var->cnt = 0;
	initial_var->is_form_spec = NON_FORMAT_SPECIFIER;
	ft_init_option(&(initial_var->opt));
}
