/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:57:39 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 17:00:35 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d	process(t_d d)
{
	d = process_set(d);
	d = process_put(d);
	if (d.con != 'u' && d.con != '%' && (d.f_pos || d.f_spa || d.v_sign))
		d = flag_sign(d);
	if ((d.con == 'o' || d.con == 'O') && (d.f_has == 1 &&
		ft_strcmp(d.val, "0") && ft_strcmp(d.val, "")))
		d = flag_hash_o(d);
	if ((d.con == 'x' || d.con == 'X') && (d.f_has == 1 &&
		ft_strcmp(d.val, "0") && ft_strcmp(d.val, "")))
		d = flag_hash_x(d);
	if (d.con == 'p')
		d = flag_hash_p(d);
	return (d);
}

t_d	process_set(t_d d)
{
	int len;

	d.v_size = ft_strlen(d.val);
	len = 0;
	if (len < d.v_size)
		len = d.v_size;
	if (len < d.wid)
		len = d.wid;
	if (d.f_neg && len <= d.v_size)
	{
		len += d.v_sign || d.f_pos || d.f_spa;
		len += d.f_has && (d.con == 'x' || d.con == 'X') ? 2 : 0;
		len += d.con == 'p' ? 2 : 0;
		len += d.f_has && (d.con == 'o' || d.con == 'O');
	}
	d.res = ft_strnew(len);
	if (d.f_zer && !d.f_neg && d.pre == -1)
		d.res = ft_memset(d.res, '0', len);
	else
		d.res = ft_memset(d.res, ' ', len);
	d.r_size = ft_strlen(d.res);
	return (d);
}

t_d	process_put(t_d d)
{
	int tmp_r;
	int tmp_v;

	if (d.f_neg)
	{
		tmp_r = d.v_sign || d.f_pos || d.f_spa;
		if ((d.con == 'x' || d.con == 'X' || d.con == 'o' ||
			d.con == 'O') && d.f_has && ft_strcmp(d.val, "0"))
			tmp_r += (d.con == 'x' || d.con == 'X' ? 2 : 1);
		if (d.con == 'p')
			tmp_r += 2;
		tmp_v = 0;
		while (d.val[tmp_v])
			d.res[tmp_r++] = d.val[tmp_v++];
	}
	else
	{
		tmp_r = d.r_size - 1;
		tmp_v = d.v_size - 1;
		while (tmp_v >= 0)
			d.res[tmp_r--] = d.val[tmp_v--];
	}
	return (d);
}
