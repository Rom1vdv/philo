/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:49 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/10 17:06:17 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int i;

	i = 0;
	while (i <= philo_datas->number_of_philos)
	{
		array_of_philos[i] = malloc(sizeof(*array_of_philos[i]));
		if (!array_of_philos[i])
			return (ERROR_ALLOCATION);
		if (pthread_create(array_of_philos[i]->philo, NULL, &run_process, array_of_philos[i]) != 0)
		{	
			while (i != 0)
				//!phtread_detach check
			return (ERROR_THREAD);
		}
		++i;
	}
}

int	join_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	i;

	i = 0;
	while (i <= philo_datas->number_of_philos)
	{
		if (pthread_join(*array_of_philos[i]->philo, NULL) != 0)
		{
			return (ERROR_THREAD);
		}
		++i;
	}
}
