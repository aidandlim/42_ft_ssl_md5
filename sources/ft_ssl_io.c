/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:53:03 by dlim              #+#    #+#             */
/*   Updated: 2019/10/21 01:44:50 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		read_check(char *input)
{
	int fd;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

char	*read_process(int fd)
{
	char	*container;
	char	*buffer;
	int		len;

	container = ft_strnew(1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((len = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[len] = '\0';
		container = ft_strjoin(container, buffer);
		buffer = ft_strnew(BUFF_SIZE);
	}
	free(buffer);
	return (container);
}

void	print_before(char *input, char *file)
{
	if (g_flag_p)
		ft_printf("%s", input);
	else
	{
		if (!g_flag_q && !g_flag_r && file != NULL)
			g_flag_s ? ft_printf("%s (\"%s\") = ", util_hash_name(1), file) :
				ft_printf("%s (%s) = ", util_hash_name(1), file);
	}
}

void	print_after(char *input, char *file)
{
	if (!g_flag_q && file != NULL && g_flag_r)
		g_flag_s ? ft_printf(" \"%s\"", file) : ft_printf(" %s", file);
	ft_printf("\n");
	g_flag_s ? g_flag_s = 0 : 0;
	g_flag_p ? g_was_p = 1 : 0;
	g_flag_p ? g_flag_p = 0 : 0;
	free(input);
}
