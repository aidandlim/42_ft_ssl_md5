/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha384.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:44 by dlim              #+#    #+#             */
/*   Updated: 2019/10/21 03:19:45 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_sha384.h"

void	sha384_init(unsigned char *input, t_sha384 *t,
	unsigned long long length)
{
	unsigned int		i;
	unsigned long long	len;

	g_a = 0xcbbb9d5dc1059ed8;
	g_b = 0x629a292a367cd507;
	g_c = 0x9159015a3070dd17;
	g_d = 0x152fecd8f70e5939;
	g_e = 0x67332667ffc00b31;
	g_f = 0x8eb44a8768581511;
	g_g = 0xdb0c2e0d64f98fa7;
	g_h = 0x47b5481dbefa4fa4;
	t->set = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
		(128 * length));
	i = -1;
	while (input[++i])
		t->set[i] = input[i];
	t->set[i] = (unsigned char)(128);
	len = i * 8;
	i = 0;
	while (i < 8)
	{
		t->set[(128 * length) - i - 1] = len >> (i * 8);
		i++;
	}
}

void	sha384_set(t_sha384 *t, int i)
{
	int					j;
	int					k;
	unsigned long long	s1;
	unsigned long long	s2;

	j = 0;
	while (j < 16)
	{
		k = 0;
		g_w[j] = 0;
		while (k < 8)
		{
			g_w[j] += (u_int64_t)t->set[i * 128 + j * 8 + k]
				<< (8 * (7 - k));
			k++;
		}
		j++;
	}
	while (j < 80)
	{
		s1 = RR_64(g_w[j - 15], 1) ^ RR_64(g_w[j - 15], 8) ^ (g_w[j - 15] >> 7);
		s2 = RR_64(g_w[j - 2], 19) ^ RR_64(g_w[j - 2], 61) ^ (g_w[j - 2] >> 6);
		g_w[j] = g_w[j - 16] + s1 + g_w[j - 7] + s2;
		j++;
	}
}

void	sha384_loop(t_sha384 *t)
{
	unsigned long long	j;
	unsigned long long	s1;
	unsigned long long	s2;
	unsigned long long	t1;
	unsigned long long	t2;

	j = 0;
	while (j < 80)
	{
		s1 = X(RR_64(t->a, 28), RR_64(t->a, 34), RR_64(t->a, 39));
		t1 = Z(t->a, t->b, t->c, s1);
		s2 = X(RR_64(t->e, 14), RR_64(t->e, 18), RR_64(t->e, 41));
		t2 = Y(t->e, t->f, t->g, t->h, s2, g_sha384[j], g_w[j]);
		t->h = t->g;
		t->g = t->f;
		t->f = t->e;
		t->e = t->d + t2;
		t->d = t->c;
		t->c = t->b;
		t->b = t->a;
		t->a = t1 + t2;
		j++;
	}
}

void	sha384_copy(t_sha384 *t, int type)
{
	if (!type)
	{
		t->a = g_a;
		t->b = g_b;
		t->c = g_c;
		t->d = g_d;
		t->e = g_e;
		t->f = g_f;
		t->g = g_g;
		t->h = g_h;
	}
	else
	{
		g_a += t->a;
		g_b += t->b;
		g_c += t->c;
		g_d += t->d;
		g_e += t->e;
		g_f += t->f;
		g_g += t->g;
		g_h += t->h;
	}
}

void	sha384(unsigned char *input)
{
	t_sha384			t;
	unsigned int		i;
	unsigned long long	length;

	i = 0;
	length = input ? (ft_strlen((char *)input) + 8) / 128 + 1 : 1;
	sha384_init(input, &t, length);
	while (i < (unsigned int)(length))
	{
		sha384_set(&t, i);
		sha384_copy(&t, 0);
		sha384_loop(&t);
		sha384_copy(&t, 1);
		i++;
	}
	ft_printf("%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx",
		g_a, g_b, g_c, g_d, g_e, g_f);
	free(t.set);
}
