/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha512.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:44 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 21:51:06 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_sha512.h"

/*
void			sha512_init(unsigned char *input, t_sha512 *t, unsigned int length)
{
	unsigned int i;
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

void			sha512_set(t_sha512 *t, unsigned int i)
{
	unsigned int j;
	unsigned long long s1;
	unsigned long long s2;
	
	j = 0;
	while (j < 16)
	{
		g_chunk[j] = (t->set[i * 128 + j * 8 + 0] << (8 * (7 - j))) +
			(t->set[i * 128 + j * 8 + 1] << (8 * (7 - j))) +
			(t->set[i * 128 + j * 8 + 2] << (8 * (7 - j))) + 
			(t->set[i * 128 + j * 8 + 3] << (8 * (7 - j))) +
			(t->set[i * 128 + j * 8 + 4] << (8 * (7 - j))) +
			(t->set[i * 128 + j * 8 + 5] << (8 * (7 - j))) +
			(t->set[i * 128 + j * 8 + 6] << (8 * (7 - j))) + 
			(t->set[i * 128 + j * 8 + 7] << (8 * (7 - j)));
		j++;
	}
	while (j < 80)
	{
		s1 = X(RR_64(g_chunk[j - 15], 1), RR_64(g_chunk[j - 15], 8), g_chunk[j - 15] >> 7);
		s2 = X(RR_64(g_chunk[j - 2], 19), RR_64(g_chunk[j - 2], 61), g_chunk[j - 2] >> 6);
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
	unsigned int j;
	unsigned long long s1;
	unsigned long long s2;
	unsigned long long t1;
	unsigned long long t2;

	j = 0;
	while (j < 80)
	{
		s1 = X(RR_64(t->a, 28), RR_64(t->a, 34), RR_64(t->a, 39));
		t1 = Y(t->e, t->f, t->g, t->h, s1, g_sha512[j], g_chunk[j]);
		s2 = X(RR_64(t->e, 14), RR_64(t->e, 18), RR_64(t->e, 41));
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

void			sha512(char *input)
{
	t_sha512 t;
	unsigned int i;
	unsigned int length;

	i = 0;
	length = ((ft_strlen((char *)input) + 8) / 128) * 128 + 128;
	sha512_init(input, &t, length);
	while (i < (length * 8) / 1024)
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
	ft_printf("%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx",
		g_a, g_b, g_c, g_d, g_e, g_f, g_g, g_h);
	free(t.set);
}
*/

typedef struct	s_sha5
{
	unsigned long long	a;
	unsigned long long	b;
	unsigned long long	c;
	unsigned long long	d;
	unsigned long long	e;
	unsigned long long	f;
	unsigned long long	g;
	unsigned long long	h;
	unsigned char		*n;
	unsigned long long	w[80];
	unsigned long long	set;
}				t_sha5;

static void		sha512_algo(int i, t_sha5 *sha)
{
	unsigned long long	s0;
	unsigned long long	s1;
	unsigned long long	ch;
	unsigned long long	temp1;
	unsigned long long	maj;

	s1 = RR_64(sha->e, 14) ^ RR_64(sha->e, 18)
		^ RR_64(sha->e, 41);
	ch = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	temp1 = sha->h + s1 + ch + g_sha512[i] + sha->w[i];
	s0 = RR_64(sha->a, 28) ^ RR_64(sha->a, 34)
		^ RR_64(sha->a, 39);
	maj = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
	sha->h = sha->g;
	sha->g = sha->f;
	sha->f = sha->e;
	sha->e = sha->d + temp1;
	sha->d = sha->c;
	sha->c = sha->b;
	sha->b = sha->a;
	sha->a = temp1 + s0 + maj;
}

static void		sha512_pre(int set, t_sha5 *sha)
{
	int			i;
	int			j;
	u_int64_t	s0;
	u_int64_t	s1;

	i = -1;
	while (++i < 16)
	{
		j = -1;
		sha->w[i] = 0;
		while (++j < 8)
			sha->w[i] += (u_int64_t)sha->n[set * 128 + i * 8 + j]
						<< (8 * (7 - j));
	}
	i = 15;
	while (++i < 80)
	{
		s0 = RR_64(sha->w[i - 15], 1) ^ RR_64(sha->w[i - 15], 8)
			^ (sha->w[i - 15] >> 7);
		s1 = RR_64(sha->w[i - 2], 19) ^ RR_64(sha->w[i - 2], 61)
			^ (sha->w[i - 2] >> 6);
		sha->w[i] = sha->w[i - 16] + s0 + sha->w[i - 7] + s1;
	}
}

/*
**	each word is 64 bit length
*/

static void		sha512_process(int set, t_sha5 *sha)
{
	int i;

	sha512_pre(set, sha);
	sha->a = g_a;
	sha->b = g_b;
	sha->c = g_c;
	sha->d = g_d;
	sha->e = g_e;
	sha->f = g_f;
	sha->g = g_g;
	sha->h = g_h;
	i = -1;
	while (++i < 80)
		sha512_algo(i, sha);
	g_a += sha->a;
	g_b += sha->b;
	g_c += sha->c;
	g_d += sha->d;
	g_e += sha->e;
	g_f += sha->f;
	g_g += sha->g;
	g_h += sha->h;
}

static void		sha512_setting(char *s, t_sha5 *sha)
{
	int			i;
	u_int64_t	length_in_bits;

	g_a = 0x6a09e667f3bcc908;
	g_b = 0xbb67ae8584caa73b;
	g_c = 0x3c6ef372fe94f82b;
	g_d = 0xa54ff53a5f1d36f1;
	g_e = 0x510e527fade682d1;
	g_f = 0x9b05688c2b3e6c1f;
	g_g = 0x1f83d9abfb41bd6b;
	g_h = 0x5be0cd19137e2179;
	sha->set = s ? (ft_strlen(s) + 8) / 128 + 1 : 1;
	sha->n = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (128 * sha->set));
	i = -1;
	while (s[++i])
		sha->n[i] = s[i];
	sha->n[i] = (unsigned char)(128);
	length_in_bits = i * 8;
	i = -1;
	while (++i < 8)
		sha->n[(128 * sha->set) - i - 1] = length_in_bits >> (i * 8);
}

void			sha512(char *s)
{
	t_sha5	sha;
	int		set;

	sha512_setting(s, &sha);
	set = -1;
	while (++set < (int)(sha.set))
		sha512_process(set, &sha);
	ft_printf("%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx%.16lx",
		g_a, g_b, g_c, g_d, g_e, g_f, g_g, g_h);
	free(sha.n);
}
