/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha512.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:44 by dlim              #+#    #+#             */
/*   Updated: 2019/10/21 20:53:44 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_sha512.h"

void	sha512_init(unsigned char *input, t_sha512 *t,
	unsigned long long length)
{
	unsigned int		i;
	unsigned long long	len;

	g_a = 0x6a09e667f3bcc908;
	g_b = 0xbb67ae8584caa73b;
	g_c = 0x3c6ef372fe94f82b;
	g_d = 0xa54ff53a5f1d36f1;
	g_e = 0x510e527fade682d1;
	g_f = 0x9b05688c2b3e6c1f;
	g_g = 0x1f83d9abfb41bd6b;
	g_h = 0x5be0cd19137e2179;
	t->set = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
		(128 * length));
	i = 0;
	while (input[i])
	{
		t->set[i] = input[i];
		i++;
	}
	t->set[i] = (unsigned char)(128);
	len = i * 8;
	i = -1;
	while (++i < 8)
		t->set[(128 * length) - i - 1] = len >> (i * 8);
}

void	sha512_set(t_sha512 *t, int i)
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
			g_w[j] += (unsigned long long)t->set[i * 128 + j * 8 + k]
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

void	sha512_loop(t_sha512 *t)
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
		t2 = Y(t->e, t->f, t->g, t->h, s2, g_sha512[j], g_w[j]);
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

void	sha512_copy(t_sha512 *t, int type)
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

void	sha512(unsigned char *input)
{
	t_sha512			t;
	unsigned int		i;
	unsigned long long	length;

	i = 0;
	length = input ? (ft_strlen((char *)input) + 8) / 128 + 1 : 1;
	sha512_init(input, &t, length);
	while (i < (unsigned int)(length))
	{
		sha512_set(&t, i);
		sha512_copy(&t, 0);
		sha512_loop(&t);
		sha512_copy(&t, 1);
		i++;
	}
	ft_printf("%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx",
		g_a, g_b, g_c, g_d, g_e, g_f, g_g, g_h);
	free(t.set);
}
