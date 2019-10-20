/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:37:10 by dlim              #+#    #+#             */
/*   Updated: 2019/10/20 04:38:00 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "printf.h"

# define BUFF_SIZE 4096

int		g_i;
int		g_hash;
int     g_flag;
int		g_flag_s;
int		g_flag_r;
int		g_flag_p;
int		g_flag_q;

void	md5(unsigned char *input);
void	sha256(unsigned char *input);
void	util_init();
int		util_hash(char *input);
int		util_flag(char *input);
void	util_error(int error_num);
int		read_check(char *input);
char	*read_process(int fd);

#endif
