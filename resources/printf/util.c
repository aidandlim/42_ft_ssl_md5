/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:48:19 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 16:43:42 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long int			util_switch_len_i(t_d d, long long int v)
{
	if (d.len == 1)
		return ((short)v);
	if (d.len == 2)
		return ((char)v);
	if (d.len == 3)
		return ((long int)v);
	if (d.con == 'p' || d.len == 4)
		return (v);
	return ((int)v);
}

unsigned long long int	util_switch_len_u(t_d d, unsigned long long int v)
{
	if (d.con != 'U' && d.len == 1)
		return ((unsigned short)v);
	if (d.con != 'U' && d.len == 2)
		return ((unsigned char)v);
	if (d.con != 'U' && d.len == 3)
		return ((unsigned long int)v);
	if (d.con == 'U' || d.len == 4)
		return (v);
	return ((unsigned int)v);
}

char					*util_get_integer(t_d d, long double v)
{
	char			*res;
	long long int	t;

	d.i = 0;
	while (d.pre != -1 && d.i < d.pre + 1)
	{
		v *= 10;
		d.i++;
	}
	if ((long long int)v % 10 >= 5)
	{
		v = v + 10;
	}
	d.i = 0;
	while (d.pre != -1 && d.i < d.pre + 1)
	{
		v /= 10;
		d.i++;
	}
	t = v;
	res = lib_itoa(d, v).val;
	return (res);
}

char					*util_get_decimal(t_d d, long double v)
{
	char *res;

	d.i = 0;
	while (d.pre != -1 && d.i < d.pre + 1)
	{
		v *= 10;
		d.i++;
	}
	if ((long long int)v % 10 >= 5)
	{
		v = v + 10;
	}
	res = ft_strnew(d.pre);
	d.i = d.pre - 1;
	v /= 10;
	while (d.pre != -1 && d.i >= 0)
	{
		res[d.i] = (long long int)v % 10 + '0';
		v /= 10;
		d.i--;
	}
	return (res);
}
