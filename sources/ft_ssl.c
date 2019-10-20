/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:36:31 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 04:43:55 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void ft_ssl_switch(char *input, char *file)
{
	if (g_flag_p)
		ft_printf("%s", input);
	else
	{
		if (!g_flag_q && !g_flag_r && file != NULL)
		{
			if(g_hash == 1)
				g_flag_s ? ft_printf("MD5 (\"%s\") = ", file) : ft_printf("MD5 (%s) = ", file);
			else if(g_hash == 2)
				g_flag_s ? ft_printf("SHA256 (\"%s\") = ", file) : ft_printf("SHA256 (%s) = ", file);
		}
	}
	if (g_hash == 1)
		md5((unsigned char *)input);
	else if(g_hash == 2)
		sha256((unsigned char *)input);
	if (!g_flag_q && file != NULL && g_flag_r)
		g_flag_s ? ft_printf(" \"%s\"", file) : ft_printf(" %s", file);
	g_flag_s ? g_flag_s = 0 : 0;
	g_flag_p ? g_flag_p = 0 : 0;
	free(input);
}

void ft_ssl_value(char *argv)
{
	char *input;
	int fd;

	if (argv == NULL)
		input = read_process(0);
	else if (g_flag_s == 1)
		input = ft_strdup(argv);
	else
	{
		if((fd = read_check(argv)) == -1)
		{
			util_error(3);
			return ;
		}
		input = read_process(fd);
	}
	ft_ssl_switch(input, argv);
	ft_printf("\n");
}

void ft_ssl(int argc, char **argv)
{
	util_init();
	if (!util_hash(argv[1]))
	{
		util_error(2);
		return ;
	}
	if (argc == 2)
		ft_ssl_value(NULL);
	while (g_i < argc)
	{
		if (!g_flag && util_flag(argv[g_i]))
		{
			if (g_flag_p)
				ft_ssl_value(NULL);
		}
		else
		{
			ft_ssl_value(argv[g_i]);
			g_flag = 1;
		}
		g_i++;
	}
}

int main(int argc, char *argv[])
{
	if(argc > 1)
		ft_ssl(argc, argv);
	else
		util_error(1);
	// system("leaks ft_ssl");
	return (0);
}
