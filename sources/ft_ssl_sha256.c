/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:44 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 20:14:21 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_sha256.h"

void	sha256_init(unsigned char *input, t_sha256 *t, unsigned int length)
{
	unsigned int i;
	long long len;

	g_a = 0x6a09e667;
	g_b = 0xbb67ae85;
	g_c = 0x3c6ef372;
	g_d = 0xa54ff53a;
	g_e = 0x510e527f;
	g_f = 0x9b05688c;
	g_g = 0x1f83d9ab;
	g_h = 0x5be0cd19;
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

void	sha256_set(t_sha256 *t, unsigned int i)
{
	unsigned int j;
	unsigned int s1;
	unsigned int s2;
	
	j = 0;
	while (j < 16)
	{
		g_chunk[j] = (t->set[i * 64 + j * 4 + 0] << 24) +
			(t->set[i * 64 + j * 4 + 1] << 16) +
			(t->set[i * 64 + j * 4 + 2] << 8) + 
			(t->set[i * 64 + j * 4 + 3] << 0);
		j++;
	}
	while (j < 64)
	{
		s1 = X(RR_32(g_chunk[j - 15], 7), RR_32(g_chunk[j - 15], 18), g_chunk[j - 15] >> 3);
		s2 = X(RR_32(g_chunk[j - 2], 17), RR_32(g_chunk[j - 2], 19), g_chunk[j - 2] >> 10);
		g_chunk[j] = g_chunk[j - 16] + s1 + g_chunk[j - 7] + s2;
		j++;
	}
}

void	sha256_loop(t_sha256 *t)
{
	unsigned int j;
	unsigned int s1;
	unsigned int s2;
	unsigned int t1;
	unsigned int t2;

	j = 0;
	while (j < 64)
	{
		s1 = X(RR_32(t->e, 6), RR_32(t->e, 11), RR_32(t->e, 25));
		t1 = Y(t->e, t->f, t->g, t->h, s1, g_sha256[j], g_chunk[j]);
		s2 = X(RR_32(t->a, 2), RR_32(t->a, 13), RR_32(t->a, 22));
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

void	sha256_copy(t_sha256 *t, int type)
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

void	sha256(unsigned char *input)
{
	t_sha256 t;
	unsigned int i;
	unsigned int length;

	i = 0;
	length = ((ft_strlen((char *)input) + 8) / 64) * 64 + 64;
	sha256_init(input, &t, length);
	while (i < (length * 8) / 512)
	{
		sha256_set(&t, i);
		sha256_copy(&t, 0);
		sha256_loop(&t);
		sha256_copy(&t, 1);
		i++;
	}
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x",
		g_a, g_b, g_c, g_d, g_e, g_f, g_g, g_h);
	free(t.set);
}
