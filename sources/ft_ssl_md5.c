/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:37 by dlim              #+#    #+#             */
/*   Updated: 2019/10/21 01:45:03 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_md5.h"

int		md5_reverse(int i)
{
	int result;

	result = (i << 24 & 0xff000000) +
		(i << 8 & 0xff0000) +
		(i >> 8 & 0xff00) +
		(i >> 24 & 0xff);
	return (result);
}

void	md5_init(unsigned char *input, t_md5 *t, unsigned int length)
{
	int				i;
	long long		len;

	g_a = 0x67452301;
	g_b = 0xefcdab89;
	g_c = 0x98badcfe;
	g_d = 0x10325476;
	t->set = (unsigned char *)ft_strnew(length);
	ft_strcpy((char *)t->set, (char *)input);
	t->set[ft_strlen((char *)input)] = 1 << 7;
	len = ft_strlen((char *)input) * 8;
	i = 0;
	while (i < 8)
	{
		t->set[length - 8 + i] = ((char *)&(len))[i];
		i++;
	}
}

void	md5_set(t_md5 *t, int i)
{
	unsigned int j;

	t->a = g_a;
	t->b = g_b;
	t->c = g_c;
	t->d = g_d;
	j = 0;
	while (j < 16)
	{
		g_chunk[j] = (t->set[i * 64 + j * 4 + 0]) +
			(t->set[i * 64 + j * 4 + 1] << 8) +
			(t->set[i * 64 + j * 4 + 2] << 16) +
			(t->set[i * 64 + j * 4 + 3] << 24);
		j++;
	}
}

void	md5_loop(t_md5 *t, int j)
{
	if (j < 16)
	{
		t->f = F(t->b, t->c, t->d);
		t->g = j;
	}
	else if (j < 32)
	{
		t->f = G(t->b, t->c, t->d);
		t->g = (5 * j + 1) & 15;
	}
	else if (j < 48)
	{
		t->f = H(t->b, t->c, t->d);
		t->g = (3 * j + 5) & 15;
	}
	else
	{
		t->f = I(t->b, t->c, t->d);
		t->g = (7 * j) & 15;
	}
	t->f = t->f + t->a + pow(2, 32) * fabs(sin(j + 1)) + g_chunk[t->g];
	t->a = t->d;
	t->d = t->c;
	t->c = t->b;
	t->b += LR_32(t->f, g_md5[j]);
}

void	md5(unsigned char *input)
{
	t_md5			t;
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;

	i = 0;
	length = ((ft_strlen((char *)input) + 8) / 64) * 64 + 64;
	md5_init(input, &t, length);
	while (i < (length * 8) / 512)
	{
		md5_set(&t, i);
		j = 0;
		while (j < 64)
			md5_loop(&t, j++);
		g_a += t.a;
		g_b += t.b;
		g_c += t.c;
		g_d += t.d;
		i++;
	}
	ft_printf("%.8x%.8x%.8x%.8x",
		md5_reverse(g_a), md5_reverse(g_b), md5_reverse(g_c), md5_reverse(g_d));
	free(t.set);
}
