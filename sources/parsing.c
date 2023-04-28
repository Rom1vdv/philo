/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:28:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/04/27 17:00:22 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
todo:
verify big int, overflow
*/

static bool	check_single_input(int value_to_parse)
{
	if (value_to_parse <= 0)
		return (false);
	return (true);
}

int	validate_input_args(char **av)
{
	int	i;
	int value_to_parse;
	
	i = 0;
	while (av[i])
	{
		value_to_parse = ft_atoi(av[i]);
		if (!check_single_input(value_to_parse))
			return (ERROR_ARG);
		++i;
	}
	return (SUCCESS);
}