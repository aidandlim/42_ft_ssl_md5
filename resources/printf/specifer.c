/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:01:33 by dlim              #+#    #+#             */
/*   Updated: 2019/09/02 19:10:02 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_d		specifer_flg(t_d d, char c)
{
	if (c == '0')
		d.f_zer = 1;
	if (c == ' ')
		d.f_spa = 1;
	if (c == '+')
		d.f_pos = 1;
	if (c == '-')
		d.f_neg = 1;
	if (c == '#')
		d.f_has = 1;
	return (d);
}

t_d		specifer_wid(t_d d, const char *s)
{
	int	result;

	if (s[d.i - 1] != '\0' && s[d.i - 1] == '.')
		return (d);
	result = 0;
	while ('0' <= s[d.i] && s[d.i] <= '9')
	{
		result = result * 10 + s[d.i] - '0';
		d.i++;
	}
	d.wid = result;
	d.i--;
	return (d);
}

t_d		specifer_pre(t_d d, const char *s)
{
	int	result;

	result = 0;
	d.i++;
	while ('0' <= s[d.i] && s[d.i] <= '9')
	{
		result = result * 10 + s[d.i] - '0';
		d.i++;
	}
	d.pre = result;
	d.i--;
	return (d);
}

t_d		specifer_len(t_d d, const char *s)
{
	if (s[d.i] == 'h')
	{
		if (s[d.i + 1] != '\0' && s[d.i + 1] == 'h')
		{
			d.len = d.len < 2 ? 2 : d.len;
			d.i++;
		}
		else
			d.len = d.len < 1 ? 1 : d.len;
	}
	if (s[d.i] == 'l')
	{
		if (s[d.i + 1] != '\0' && s[d.i + 1] == 'l')
		{
			d.len = d.len < 4 ? 4 : d.len;
			d.i++;
		}
		else
			d.len = d.len < 3 ? 3 : d.len;
	}
	if (s[d.i] == 'L')
		d.len = d.len < 5 ? 5 : d.len;
	if (s[d.i] == 'z' || s[d.i] == 'j')
		d.len = d.len < 6 ? 6 : d.len;
	return (d);
}

char	specifer_con(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (c);
	if (c == 'u' || c == 'U')
		return (c);
	if (c == 'x' || c == 'X' || c == 'p')
		return (c);
	if (c == 'o' || c == 'O')
		return (c);
	if (c == 'f' || c == 'F')
		return (c);
	if (c == 'c' || c == 'C')
		return (c);
	if (c == '%')
		return (c);
	if (c == 'Z')
		return (c);
	if (c == 's' || c == 'S')
		return (c);
	return (0);
}
