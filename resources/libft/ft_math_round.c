/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:23:25 by dlim              #+#    #+#             */
/*   Updated: 2019/09/01 23:34:43 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	math_round(double input, int pos)
{
	double temp;

	temp = input * math_pow(10, pos);
	temp = (long)(temp + 0.5);
	temp = temp / math_pow(10, pos);
	return (temp);
}
