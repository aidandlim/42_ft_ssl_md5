/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:16:42 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 17:03:51 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d	lib_itoa(t_d d, long long int v)
{
	size_t i;

	if (v - 1 == 9223372036854775807)
	{
		d.val = ft_strnew(20);
		d.val = ft_strcpy(d.val, (char *)"-9223372036854775808");
		d.v_sign = 0;
		return (d);
	}
	i = ft_getdigit(v);
	d.val = ft_strnew(i--);
	d.val[i--] = v % 10 + '0';
	while (v /= 10)
		d.val[i--] = v % 10 + '0';
	return (d);
}

t_d	lib_utoa(t_d d, unsigned long long int v)
{
	size_t i;

	i = ft_getudigit(v);
	d.val = ft_strnew(i--);
	d.val[i--] = v % 10 + '0';
	while (v /= 10)
		d.val[i--] = v % 10 + '0';
	return (d);
}

t_d	lib_otoa(t_d d, unsigned long long int v)
{
	int						i;
	unsigned long long int	t;

	if (v == 0)
	{
		d.val = ft_strnew(1);
		d.val[0] = '0';
		return (d);
	}
	i = 0;
	t = v;
	while (t /= 8)
		i++;
	d.val = ft_strnew(i + 1);
	while (v != 0)
	{
		d.val[i] = v % 8 + '0';
		v /= 8;
		i--;
	}
	return (d);
}

t_d	lib_xtoa(t_d d, unsigned long long int v)
{
	int						i;
	unsigned long long int	t;

	if (v == 0)
	{
		d.val = ft_strnew(1);
		d.val[0] = '0';
		return (d);
	}
	i = 0;
	t = v;
	while (t /= 16)
		i++;
	d.val = ft_strnew(i + 1);
	while (v != 0)
	{
		t = v % 16;
		v /= 16;
		if (10 <= t)
			d.val[i] += (d.con == 'X' ? 'A' : 'a') + t - 10;
		else
			d.val[i] += t + '0';
		i--;
	}
	return (d);
}

t_d	lib_ftoa(t_d d, long double v)
{
	char *part_i;
	char *dot;
	char *part_d;

	if (v < 0)
		d.v_sign = 1;
	part_i = util_get_integer(d, v);
	part_d = util_get_decimal(d, v);
	dot = ft_strnew(1);
	dot[0] = '.';
	if (d.pre == 0)
	{
		if (d.f_has)
			d.val = ft_strjoin(part_i, dot);
		else
		{
			d.val = part_i;
			free(dot);
		}
	}
	else
		d.val = ft_strjoin(ft_strjoin(part_i, dot), part_d);
	return (d);
}
