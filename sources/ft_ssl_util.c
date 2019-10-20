/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:50 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 04:37:20 by dlim             ###   ########.fr       */
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
}

int util_hash(char *input)
{
	if (!ft_strcmp(input, "md5") || !ft_strcmp(input, "MD5"))
		g_hash = 1;
	else if (!ft_strcmp(input, "sha256") || !ft_strcmp(input, "SHA256"))
		g_hash = 2;
	else
		return (0);
	return (1);
}

int util_flag(char *input)
{
	if (!ft_strcmp(input, "-s"))
		g_flag_s = 1;
	else if (!ft_strcmp(input, "-r"))
		g_flag_r = 1;
	else if (!ft_strcmp(input, "-p"))
		g_flag_p = 1;
	else if (!ft_strcmp(input, "-q"))
		g_flag_q = 1;
	else
		return (0);
	return (1);
}

void util_error(int error_num)
{
	if (error_num == 1)
		ft_printf("error : usage\n");
	else if (error_num == 2)
		ft_printf("error : hash\n");
	else if (error_num == 3)
		ft_printf("error : file\n");
}