/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:30:06 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:36 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s || !(result = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(result + i) = *(s + start);
		i++;
		start++;
	}
	return (result);
}
