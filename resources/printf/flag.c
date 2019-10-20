/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:57:39 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 16:58:49 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d		flag_sign(t_d d)
{
	char *tmp;

	if (!d.f_neg && d.v_size >= d.r_size)
	{
		tmp = ft_strnew(1);
		if (d.v_sign)
			tmp[0] = '-';
		else
			tmp[0] = d.f_pos ? '+' : ' ';
		d.res = ft_strjoin(tmp, d.res);
	}
	else
	{
		d.i = 0;
		while (d.res[d.i] == ' ')
			d.i++;
		if ((d.f_zer && d.wid > d.v_size && !d.i) || (!d.pre && d.f_neg))
			d.res[0] = flag_get_sign(d);
		else
			d.res[d.i - 1] = flag_get_sign(d);
	}
	return (d);
}

char	flag_get_sign(t_d d)
{
	if (d.v_sign)
		return ('-');
	else
	{
		if (d.f_pos)
			return ('+');
		else
			return (' ');
	}
}

t_d		flag_hash_o(t_d d)
{
	char *tmp;

	if (d.f_has == 1 && ft_strcmp(d.val, "0") && ft_strcmp(d.val, ""))
	{
		if (d.res && d.res[0] != '0')
		{
			if (!d.f_neg && d.r_size < d.v_size + 1)
			{
				tmp = ft_strnew(1);
				tmp[0] = '0';
				d.res = ft_strjoin(tmp, d.res);
			}
			else
			{
				d.i = 0;
				while (!d.f_zer && d.res[d.i] == ' ')
					d.i++;
				d.res[d.f_zer ? 0 : d.i - 1] = '0';
			}
		}
	}
	return (d);
}

t_d		flag_hash_x(t_d d)
{
	char *tmp;

	if (!d.f_neg && d.r_size <= d.v_size)
	{
		tmp = ft_strnew(2);
		tmp[0] = '0';
		tmp[1] = d.con == 'X' ? 'X' : 'x';
		d.res = ft_strjoin(tmp, d.res);
	}
	else if (!d.f_neg && d.r_size == d.v_size + 1)
	{
		tmp = ft_strnew(1);
		tmp[0] = '0';
		d.res[0] = d.con == 'X' ? 'X' : 'x';
		d.res = ft_strjoin(tmp, d.res);
	}
	else
	{
		d.i = 0;
		while (!d.f_zer && d.res[d.i] == ' ')
			d.i++;
		d.res[d.f_zer ? 0 : d.i - 2] = '0';
		d.res[d.f_zer ? 1 : d.i - 1] = d.con == 'X' ? 'X' : 'x';
	}
	return (d);
}

t_d		flag_hash_p(t_d d)
{
	char *tmp;

	if (!d.f_neg && d.r_size <= d.v_size)
	{
		tmp = ft_strnew(2);
		tmp[0] = '0';
		tmp[1] = 'x';
		d.res = ft_strjoin(tmp, d.res);
	}
	else if (!d.f_neg && d.r_size == d.v_size + 1)
	{
		tmp = ft_strnew(1);
		tmp[0] = '0';
		d.res[0] = 'x';
		d.res = ft_strjoin(tmp, d.res);
	}
	else
	{
		d.i = 0;
		while (!d.f_zer && d.res[d.i] == ' ')
			d.i++;
		d.res[d.f_zer ? 0 : d.i - 2] = '0';
		d.res[d.f_zer ? 1 : d.i - 1] = 'x';
	}
	return (d);
}
