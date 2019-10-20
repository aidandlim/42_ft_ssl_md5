/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:53:03 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 02:41:35 by dlim             ###   ########.fr       */
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
    int 	len;

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