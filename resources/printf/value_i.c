/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:42:13 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 16:56:41 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d	value_i(t_d d, long long int v)
{
	char *c_tmp;

	if (d.len == 6)
		d.len = 4;
	v = util_switch_len_i(d, v);
	if (d.pre == 0 && v == 0)
		d.val = ft_strnew(0);
	else
	{
		if (v < 0)
		{
			v = -v;
			d.v_sign = 1;
		}
		d = lib_itoa(d, v);
		if (d.pre != -1 && (int)ft_strlen(d.val) < d.pre)
		{
			c_tmp = ft_strnew(d.pre - ft_strlen(d.val));
			c_tmp = ft_memset(c_tmp, '0', d.pre - ft_strlen(d.val));
			d.val = ft_strjoin(c_tmp, d.val);
		}
	}
	return (d);
}

t_d	value_u(t_d d, unsigned long long int v)
{
	char *c_tmp;

	if (d.len == 6)
		d.len = 4;
	v = util_switch_len_u(d, v);
	if (d.pre == 0 && v == 0)
		d.val = ft_strnew(0);
	else
	{
		d = lib_utoa(d, v);
		if (d.pre != -1 && (int)ft_strlen(d.val) < d.pre)
		{
			c_tmp = ft_strnew(d.pre - ft_strlen(d.val));
			c_tmp = ft_memset(c_tmp, '0', d.pre - ft_strlen(d.val));
			d.val = ft_strjoin(c_tmp, d.val);
		}
	}
	return (d);
}

t_d	value_o(t_d d, unsigned long long int v)
{
	char *c_tmp;

	v = util_switch_len_u(d, v);
	if (d.pre == 0 && !d.f_has && v == 0)
		d.val = ft_strnew(0);
	else
	{
		d = lib_otoa(d, v);
		if (d.pre != -1 && (int)ft_strlen(d.val) < d.pre)
		{
			c_tmp = ft_strnew(d.pre - ft_strlen(d.val));
			c_tmp = ft_memset(c_tmp, '0', d.pre - ft_strlen(d.val));
			d.val = ft_strjoin(c_tmp, d.val);
		}
	}
	return (d);
}

t_d	value_x(t_d d, unsigned long long int v)
{
	char *c_tmp;

	if (d.len == 6)
		d.len = 4;
	if (d.con == 'p')
	{
		d.len = 4;
		d.f_has = 1;
	}
	v = util_switch_len_u(d, v);
	if (d.pre == 0 && v == 0)
		d.val = ft_strnew(0);
	else
	{
		d = lib_xtoa(d, v);
		if (d.pre != -1 && (int)ft_strlen(d.val) < d.pre)
		{
			c_tmp = ft_strnew(d.pre - ft_strlen(d.val));
			c_tmp = ft_memset(c_tmp, '0', d.pre - ft_strlen(d.val));
			d.val = ft_strjoin(c_tmp, d.val);
		}
	}
	return (d);
}
