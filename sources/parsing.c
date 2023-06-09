/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:28:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/11 17:37:20 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (my_atoi(av[i]) == ERROR_ARG_VALIDITY)
		{
			return (ERROR_ARG_VALIDITY);
		}
		++i;
	}
	return (SUCCESS);
}
