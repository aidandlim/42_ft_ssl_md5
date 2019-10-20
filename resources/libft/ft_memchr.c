/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:34:15 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:17:42 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*result;

	i = 0;
	result = (const char *)s;
	while (i < n)
	{
		if (*(result + i) == (char)c)
			return ((void *)result + i);
		i++;
	}
	return (NULL);
}
