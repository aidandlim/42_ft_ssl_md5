/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwordscount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:36:20 by dlim              #+#    #+#             */
/*   Updated: 2019/05/18 20:23:30 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getwordscount(char const *str, char c)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (*(str + i))
	{
		while (*(str + i) == c)
			i++;
		if (*(str + i) != c && *(str + i) != '\0')
			result++;
		while (*(str + i) != c && *(str + i) != '\0')
			i++;
	}
	return (result);
}
