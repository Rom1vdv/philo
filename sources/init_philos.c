/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:49 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 17:53:27 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_threads(t_philo **array_of_philos, t_philo_datas *philo_datas, int thread_index)
{
	array_of_philos[thread_index] = malloc(sizeof(*array_of_philos[thread_index]));
	if (!array_of_philos[thread_index])
		return (ERROR_ALLOCATION);
	array_of_philos[thread_index]->eat_count = 0;
	array_of_philos[thread_index]->philo_id = thread_index + 1;
	array_of_philos[thread_index]->datas = philo_datas;
	pthread_mutex_init(&array_of_philos[thread_index]->left_fork, NULL);
	pthread_mutex_init(&array_of_philos[thread_index]->right_fork, NULL);
	return (SUCCESS);
}
int	create_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	thread_index;
	
	thread_index = 0;
	philo_datas->start_time = calculate_time();
	// pthread_mutex_init(&philo_datas->mutex_death_status, NULL);
	while (thread_index <= philo_datas->number_of_philos)
	{
		allocate_threads(array_of_philos, philo_datas, thread_index);
		if (pthread_create(&(array_of_philos[thread_index]->philo), NULL,
			&run_process, array_of_philos[thread_index]) != 0)
		{	
			return (ERROR_THREAD);
		}
		++thread_index;
	}
	return (SUCCESS);
}


int	join_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	i;

	i = 0;
	while (i <= philo_datas->number_of_philos)
	{
		if (pthread_join(array_of_philos[i]->philo, NULL) != 0)
		{
			return (ERROR_THREAD);
		}
		++i;
	}
	return (SUCCESS);
}
;