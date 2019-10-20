/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:04:36 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 16:44:40 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "stdarg.h"
# include "libft.h"
# define ISFLG(c) (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0')
# define ISNUM(c) ('1' <= c && c <= '9')
# define ISDOT(c) (c == '.')
# define ISLEN(c) (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z')

typedef struct			s_d {
	int					i;
	int					f_zer;
	int					f_pos;
	int					f_neg;
	int					f_spa;
	int					f_has;
	int					wid;
	int					pre;
	int					len;
	char				con;
	char				*res;
	int					r_size;
	char				*val;
	int					v_size;
	int					v_sign;
	int					err;
}						t_d;

int						ft_printf(const char *format, ...);
int						core(const char *format, va_list ap);
int						core_init(const char *format, int i, va_list ap);
int						core_deliver(t_d d, va_list ap);
int						core_end(const char *format, int i);
int						core_print(t_d d);
t_d						specifer_flg(t_d d, char c);
t_d						specifer_wid(t_d d, const char *s);
t_d						specifer_pre(t_d d, const char *s);
t_d						specifer_len(t_d d, const char *s);
char					specifer_con(char c);
t_d						value_c(t_d d, int v);
t_d						value_s(t_d d, char *v);
t_d						value_i(t_d d, long long int v);
t_d						value_u(t_d d, unsigned long long int v);
t_d						value_o(t_d d, unsigned long long int v);
t_d						value_x(t_d d, unsigned long long int v);
t_d						value_f(t_d d, double v);
t_d						value_lf(t_d d, long double v);
t_d						process(t_d d);
t_d						process_set(t_d d);
t_d						process_put(t_d d);
t_d						flag_sign(t_d d);
char					flag_get_sign(t_d d);
t_d						flag_hash_o(t_d d);
t_d						flag_hash_x(t_d d);
t_d						flag_hash_p(t_d d);
t_d						lib_itoa(t_d d, long long int v);
t_d						lib_utoa(t_d d, unsigned long long int v);
t_d						lib_otoa(t_d d, unsigned long long int v);
t_d						lib_xtoa(t_d d, unsigned long long int v);
t_d						lib_ftoa(t_d d, long double v);
long long int			util_switch_len_i(t_d d, long long int v);
unsigned long long int	util_switch_len_u(t_d d, unsigned long long int v);
char					*util_get_integer(t_d d, long double v);
char					*util_get_decimal(t_d d, long double v);

#endif
