/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:51:20 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/20 16:14:28 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include "./libft.h"

# define FORMAT_SPECIFIER 1
# define NON_FORMAT_SPECIFIER 0

typedef enum e_switch
{
	OFF,
	ON
}	t_switch;

typedef enum e_sign
{
	SIGN_MINUS = -1,
	SIGN_NULL = 0,
	SIGN_PLUS = 1,
	SIGN_L_HEX = 2,
	SIGN_U_HEX = 3
}	t_sign;

typedef struct s_flags
{
	t_switch	minus;
	t_switch	zero;
	t_switch	hash;
	t_switch	blank;
	t_switch	plus;
}	t_flags;

typedef struct s_options
{
	t_flags	flags;
	int		width;
	int		prec;
}	t_options;

typedef struct s_strinfo
{
	char		*str;
	int			len;
	t_sign		sign;
}	t_strinfo;

typedef struct s_initial_var
{
	int			is_form_spec;
	int			cnt;
	t_options	opt;
}	t_initial_var;

// ft_printf.c
int		ft_print(va_list ap, t_options *option, const char c, int *cnt);
int		classify_form(va_list ap, t_options *option, const char c, int *cnt);
void	ft_put_non_form(char c, int *is_form_spec, int *cnt);
int		ft_printf(const char *format, ...);
void	ft_init_var(t_initial_var *initial_var);

// ft_init_get.c
void	ft_init_option(t_options *options);
void	ft_init_strinfo(t_strinfo *strinfo);
int		ft_get_diuinfo(t_strinfo *strinfo, va_list ap, const char c);
int		ft_get_pxxinfo(t_strinfo *strinfo, va_list ap, const char c);

// ft_printf_utils.c
void	ft_update_flag(t_options *option, const char c);
void	ft_update_width_preq(t_options *option, const char c);
char	*ft_itoa_base(unsigned long long nbr, char *base, \
		unsigned long long base_length);
void	check_both_zero(t_strinfo *strinfo, t_options *opt);

// ft_printf_detail.c
int		ft_print_char(va_list ap, t_options *option, int *cnt, const char fs);
int		ft_print_str(va_list ap, t_options *option, int *cnt);
int		ft_print_nbr(va_list ap, t_options *option, int *cnt, const char c);
int		ft_print_pxx(va_list ap, t_options *option, int *cnt, const char c);
void	put_space_zero(t_switch flag, int len_space_zero, int *cnt);

#endif
