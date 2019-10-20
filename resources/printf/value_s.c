/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:41:48 by dlim              #+#    #+#             */
/*   Updated: 2019/09/01 23:32:05 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d	value_c(t_d d, int v)
{
	if (d.con == 'Z')
	{
		d.f_spa = 0;
		d.f_zer = 0;
	}
	d.val = ft_strnew(1);
	d.val[0] = v;
	return (d);
}

t_d	value_s(t_d d, char *v)
{
	int i;
	int len;

	if (v == NULL)
	{
		d.val = ft_strnew(d.pre == -1 ? 6 : d.pre);
		d.val = ft_strncpy(d.val, "(null)", d.pre == -1 ? 6 : d.pre);
	}
	else
	{
		len = ft_strlen(v) >= (size_t)d.pre ? d.pre : ft_strlen(v);
		d.val = ft_strnew(len);
		i = 0;
		while (i < len)
		{
			d.val[i] = v[i];
			i++;
		}
	}
	return (d);
}
