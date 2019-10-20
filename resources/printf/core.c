/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:44:38 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 16:37:12 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	core(const char *format, va_list ap)
{
	int	result;
	int	i;
	int temp;

	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = core_init(format, i + 1, ap);
			if (temp == -1)
				break ;
			result = result + temp;
			i = core_end(format, i + 1);
		}
		else
		{
			ft_putchar(format[i]);
			result++;
			i++;
		}
	}
	return (result);
}

int	core_init(const char *format, int i, va_list ap)
{
	t_d	d;
	int	result;

	ft_memset(&d, 0, sizeof(d));
	d.i = i;
	result = 0;
	d.pre = -1;
	while (format[d.i])
	{
		if ((d.con = specifer_con(format[d.i])) != 0)
			break ;
		if (ISFLG(format[d.i]))
			d = specifer_flg(d, format[d.i]);
		if (ISNUM(format[d.i]))
			d = specifer_wid(d, format);
		if (ISDOT(format[d.i]))
			d = specifer_pre(d, format);
		if (ISLEN(format[d.i]))
			d = specifer_len(d, format);
		d.i++;
	}
	if (d.con == 0)
		return (-1);
	result = core_deliver(d, ap);
	return (result);
}

int	core_deliver(t_d d, va_list ap)
{
	if (d.con == 'c' || d.con == 'C')
		d = value_c(d, va_arg(ap, int));
	if (d.con == '%')
		d = value_c(d, '%');
	if (d.con == 'Z')
		d = value_c(d, 'Z');
	if (d.con == 's' || d.con == 'S')
		d = value_s(d, va_arg(ap, char *));
	if (d.con == 'd' || d.con == 'D' || d.con == 'i')
		d = value_i(d, va_arg(ap, long long int));
	if (d.con == 'u' || d.con == 'U')
		d = value_u(d, va_arg(ap, unsigned long long int));
	if (d.con == 'o' || d.con == 'O')
		d = value_o(d, va_arg(ap, unsigned long long int));
	if (d.con == 'x' || d.con == 'X' || d.con == 'p')
		d = value_x(d, va_arg(ap, unsigned long long int));
	if (d.con == 'f' || d.con == 'F')
		d = d.len == 5 ? value_lf(d, va_arg(ap, long double)) :
			value_f(d, va_arg(ap, double));
	d = process(d);
	return (core_print(d));
}

int	core_end(const char *format, int i)
{
	int	skip;

	skip = 0;
	while (specifer_con(format[i + skip]) == 0)
	{
		skip++;
	}
	return (i + 1 + skip);
}

int	core_print(t_d d)
{
	int result;

	if (d.con == 'c' && !ft_strcmp(d.val, ""))
	{
		d.i = 0;
		if (d.f_neg)
		{
			ft_putchar(0);
			while (d.i++ < d.wid - 1)
				ft_putchar(' ');
		}
		else
		{
			while (d.i++ < d.wid - 1)
				ft_putchar(' ');
			ft_putchar(0);
		}
		return (d.i);
	}
	result = ft_strlen(d.res);
	ft_putstr(d.res);
	free(d.res);
	free(d.val);
	return (result);
}
