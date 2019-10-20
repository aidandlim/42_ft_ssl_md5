/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:36:20 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:23 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	int		check;

	i = 0;
	check = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		if (*(haystack + i) == *(needle + 0))
		{
			temp = i;
			check = 0;
			while (*(haystack + temp) && *(needle + j) && temp < len)
				if (*(haystack + temp++) != *(needle + j++))
					check = 1;
			if (!check && !*(needle + j))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
