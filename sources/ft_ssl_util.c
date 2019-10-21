/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:50 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 18:42:48 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void util_init()
{
	g_i = 2;
	g_hash = 0;
	g_flag = 0;
	g_flag_s = 0;
	g_flag_r = 0;
	g_flag_p = 0;
	g_flag_q = 0;
	g_was_p = 0;
}

int util_hash(char *input)
{
	if (!ft_strcmp(input, "md5") || !ft_strcmp(input, "MD5"))
		g_hash = 1;
	else if (!ft_strcmp(input, "sha256") || !ft_strcmp(input, "SHA256"))
		g_hash = 2;
	else if (!ft_strcmp(input, "sha224") || !ft_strcmp(input, "SHA224"))
		g_hash = 3;
	else if (!ft_strcmp(input, "sha512") || !ft_strcmp(input, "SHA512"))
		g_hash = 4;
	else if (!ft_strcmp(input, "sha384") || !ft_strcmp(input, "SHA384"))
		g_hash = 5;
	else
		return (0);
	return (1);
}

char *util_hash_name(int type)
{
	if (g_hash == 1)
		return (type ? "MD5" : "md5");
	if (g_hash == 2)
		return (type ? "SHA256" : "sha256");
	if (g_hash == 3)
		return (type ? "SHA224" : "sha224");
	if (g_hash == 4)
		return (type ? "SHA512" : "sha512");
	if (g_hash == 5)
		return (type ? "SHA384" : "sha384");
	return (NULL);
}

int util_flag(char *input)
{
	if (!ft_strcmp(input, "-s") && !g_flag_s)
		g_flag_s = 1;
	else if (!ft_strcmp(input, "-r"))
		g_flag_r = 1;
	else if (!ft_strcmp(input, "-p") && !g_was_p)
		g_flag_p = 1;
	else if (!ft_strcmp(input, "-q"))
		g_flag_q = 1;
	else
		return (0);
	return (1);
}

void util_error(int error_num, char *str)
{
	if (error_num == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (error_num == 2)
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nMessage Digest commands:\nmd5\nsha256\nsha224\nsha512\nsha384\n\n", str);
	else if (error_num == 3)
		ft_printf("ft_ssl: %s: %s: No such file or directory\n", util_hash_name(0), str);
}