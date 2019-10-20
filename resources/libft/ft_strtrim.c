/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:30:43 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:39 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*result;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (ft_isenter(*(s + j - 1)) || ft_isspace(*(s + j - 1)))
		j--;
	i = 0;
	while (ft_isenter(*(s + i)) || ft_isspace(*(s + i)))
	{
		j--;
		i++;
	}
	if (!(result = (char*)malloc(sizeof(char) * ((j < 0 ? 0 : j) + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		*(result + i) = *(s + i);
	*(result + i) = '\0';
	return (result);
}
