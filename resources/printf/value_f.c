/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:42:13 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 14:09:37 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d	value_f(t_d d, double v)
{
	if (v < 0)
	{
		v = -v;
		d.v_sign = 1;
	}
	d.pre = d.pre == -1 ? 6 : d.pre;
	d = lib_ftoa(d, v);
	return (d);
}

t_d	value_lf(t_d d, long double v)
{
	if (v < 0)
	{
		v = -v;
		d.v_sign = 1;
	}
	d.pre = d.pre == -1 ? 6 : d.pre;
	d = lib_ftoa(d, v);
	return (d);
}
