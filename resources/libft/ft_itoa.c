/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:21:57 by dlim              #+#    #+#             */
/*   Updated: 2019/09/01 23:33:02 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	temp;
	char			*result;

	i = ft_getdigit(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		i++;
	}
	if (!(result = ft_strnew(i--)))
		return (NULL);
	*(result + i--) = temp % 10 + '0';
	while (temp /= 10)
		*(result + i--) = temp % 10 + '0';
	if (n < 0)
		*(result + 0) = '-';
	return (result);
}
