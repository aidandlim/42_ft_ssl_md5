/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:35:33 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:19:31 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;

	if (!(temp = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strncpy(temp, s1, ft_strlen(s1));
	return (temp);
}
