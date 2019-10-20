/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:35:21 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:19:14 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (ft_strncmp(s1, s2, ft_strlen(s1)));
	else
		return (ft_strncmp(s1, s2, ft_strlen(s2)));
}
