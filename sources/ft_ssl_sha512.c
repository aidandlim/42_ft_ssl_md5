/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha512.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:44 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 18:50:55 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_sha512.h"

unsigned long long	sha512_rr(unsigned long long num, unsigned long long rot)
{
	unsigned long long i;
	unsigned long long r;

	i = 0;
	while (i < rot)
	{
		r = num & 1;
		num = num >> 1;
		num += r << 31;
		i++;
	}
	return (num);
}

void			sha512_init(unsigned char *input, t_sha512 *t, unsigned long long length)
{
	unsigned long long i;
	long long len;

	g_a = 0x6a09e667f3bcc908;
	g_b = 0xbb67ae8584caa73b;
	g_c = 0x3c6ef372fe94f82b;
	g_d = 0xa54ff53a5f1d36f1;
	g_e = 0x510e527fade682d1;
	g_f = 0x9b05688c2b3e6c1f;
	g_g = 0x1f83d9abfb41bd6b;
	g_h = 0x5be0cd19137e2179;
	t->set = (unsigned char*)ft_strnew(length);
	ft_strcpy((char *)t->set, (char *)input);
	len = ft_strlen((char *)input) * 8;
	t->set[ft_strlen((char *)input)] = 1 << 7;
	i = 0;
	while (i < 8)
	{
		t->set[length - 8 + i] = ((unsigned char *)&(len))[7 - i];
		i++;
	}
}

void			sha512_set(t_sha512 *t, unsigned long long i)
{
	unsigned long long j;
	unsigned long long s1;
	unsigned long long s2;
	
	j = 0;
	while (j < 16)
	{
		g_chunk[j] = (t->set[i * 64 + j * 4 + 0] << 24) +
			(t->set[i * 64 + j * 4 + 1] << 16) +
			(t->set[i * 64 + j * 4 + 2] << 8) + 
			(t->set[i * 64 + j * 4 + 3] << 0);
		j++;
	}
	while (j < 80)
	{
		s1 = X(sha512_rr(g_chunk[j - 15], 1), sha512_rr(g_chunk[j - 15], 8), g_chunk[j - 15] >> 7);
		s2 = X(sha512_rr(g_chunk[j - 2], 19), sha512_rr(g_chunk[j - 2], 61), g_chunk[j - 2] >> 6);
		g_chunk[j] = g_chunk[j - 16] + s1 + g_chunk[j - 7] + s2;
		j++;
	}
	t->a = g_a;
	t->b = g_b;
	t->c = g_c;
	t->d = g_d;
}

void			sha512_loop(t_sha512 *t)
{
	unsigned long long j;
	unsigned long long s1;
	unsigned long long s2;
	unsigned long long t1;
	unsigned long long t2;

	j = 0;
	while (j < 80)
	{
		s1 = X(sha512_rr(t->a, 28), sha512_rr(t->a, 34), sha512_rr(t->a, 39));
		t1 = Y(t->e, t->f, t->g, t->h, s1, g_sha512[j], g_chunk[j]);
		s2 = X(sha512_rr(t->e, 14), sha512_rr(t->e, 18), sha512_rr(t->e, 41));
		t2 = Z(t->a, t->b, t->c, s2);
		t->h = t->g;
		t->g = t->f;
		t->f = t->e;
		t->e = t->d + t1;
		t->d = t->c;
		t->c = t->b;
		t->b = t->a;
		t->a = t1 + t2;
		j++;
	}
}

void			sha512(unsigned char *input)
{
	t_sha512 t;
	unsigned long long i;
	unsigned long long length;

	i = 0;
	length = ((ft_strlen((char *)input) + 8) / 64) * 64 + 64;
	sha512_init(input, &t, length);
	while (i < (length * 8) / 512)
	{
		sha512_set(&t, i);
		t.e = g_e;
		t.f = g_f;
		t.g = g_g;
		t.h = g_h;
		sha512_loop(&t);
		g_a += t.a;
		g_b += t.b;
		g_c += t.c;
		g_d += t.d;
		g_e += t.e;
		g_f += t.f;
		g_g += t.g;
		g_h += t.h;
		i++;
	}
	ft_printf("%.16x%.16x%.16x%.16x%.16x%.16x%.16x%.16x",
		g_a, g_b, g_c, g_d, g_e, g_f, g_g, g_h);
	free(t.set);
}
