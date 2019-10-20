/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:36:15 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:14 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(src + i))
		{
			*(dst + i) = *(src + i);
		}
		else
		{
			while (i < len)
			{
				*(dst + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dst);
}
