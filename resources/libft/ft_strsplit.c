/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:29:26 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:29 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	if (!s || !(result = (char **)malloc(sizeof(*result) *
		(ft_getwordscount(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_getwordscount(s, c))
	{
		k = 0;
		if (!(*(result + i) = ft_strnew(ft_getwordlen(&*(s + j), c) + 1)))
			*(result + i) = NULL;
		while (*(s + j) == c)
			j++;
		while (*(s + j) && *(s + j) != c)
			*(*(result + i) + k++) = *(s + j++);
		*(*(result + i) + k) = '\0';
		i++;
	}
	*(result + i) = 0;
	return (result);
}
