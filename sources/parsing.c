/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:28:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/08 15:10:16 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input_args(char **av)
{
	int	i;
	int value_to_parse;
	
	i = 0;
	while (av[i])
	{
		if (my_atoi(av[i]) == ERROR_ARG)
		{
			return (ERROR_ARG);
		}
		++i;
	}
	return (SUCCESS);
}
