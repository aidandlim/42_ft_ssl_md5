/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:34:36 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:17:54 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	temp1 = (char *)src;
	temp2 = (char *)dst;
	if (temp1 < temp2)
	{
		while ((int)(--len) >= 0)
			*(temp2 + len) = *(temp1 + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(temp2 + i) = *(temp1 + i);
			i++;
		}
	}
	return (dst);
}
