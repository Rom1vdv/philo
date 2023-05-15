/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:52:46 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/11 17:36:34 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_iswhitespace(const char *str, int i)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	ft_sign(const char *str, int i, int *sign)
{
	*sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = 1;
		i++;
	}
	return (i);
}

int	my_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 0;
	number = 0;
	i = ft_iswhitespace(str, i);
	i = ft_sign(str, i, &sign);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number += str[i] - 48;
		}
		else
			return (ERROR_ARG_VALIDITY);
		i++;
	}
	if (sign == 1)
		number *= -1;
	if (number <= 0 || number >= 2147483648)
		return (ERROR_ARG_VALIDITY);
	return ((int) number);
}
