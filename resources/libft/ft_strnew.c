/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:28:49 by dlim              #+#    #+#             */
/*   Updated: 2019/05/10 15:20:20 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	else
		return (ft_memset(result, 0, size + 1));
}
