/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:49 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/17 15:21:06 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_threads_memory(t_philo **array_of_philos,
		t_philo_datas *philo_datas)
{
	int	thread_index;

	thread_index = 0;
	while (thread_index < philo_datas->number_of_philos)
	{
		array_of_philos[thread_index] = malloc(sizeof
				(*array_of_philos[thread_index]));
		if (!array_of_philos[thread_index])
			return (ERROR_ALLOCATION);
		array_of_philos[thread_index]->eat_count = 0;
		array_of_philos[thread_index]->philo_id = thread_index + 1;
		array_of_philos[thread_index]->datas = philo_datas;
		array_of_philos[thread_index]->left_fork = &philo_datas
			->forks[thread_index];
		array_of_philos[thread_index]->right_fork = &philo_datas
			->forks[(thread_index + 1) % philo_datas->number_of_philos];
		++thread_index;
	}
	return (SUCCESS);
}

int	create_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	thread_index;
	int	allocate_threads_error;

	thread_index = 0;
	// pthread_mutex_init(&philo_datas->mutex_death_status, NULL);
	allocate_threads_error = allocate_threads_memory(array_of_philos,
			philo_datas);
	philo_datas->start_time = calculate_time();
	while (thread_index < philo_datas->number_of_philos)
	{
		if (pthread_create(&(array_of_philos[thread_index]->philo), NULL,
				&run_process, array_of_philos[thread_index]) != 0)
		{	
			return (ERROR_THREAD);
		}
		++thread_index;
	}
	return (SUCCESS);
}
int	init_mutexes(t_philo_datas *philo_datas)
{
	int	i;
	
	i = 0;
	while (i < philo_datas->number_of_philos)
	{
		if (pthread_mutex_init(&philo_datas->forks[i], NULL) != 0)
			return (ERROR_THREAD);
		++i;
	}
	if (pthread_mutex_init(&philo_datas->mutex_last_meal, NULL) != 0)
		return (ERROR_THREAD);
	if (pthread_mutex_init(&philo_datas->mutex_eat_count, NULL) != 0)
		return (ERROR_THREAD);
	if (pthread_mutex_init(&philo_datas->message, NULL) != 0)
		return (ERROR_THREAD);
	if (pthread_mutex_init(&philo_datas->mutex_death_status, NULL) != 0)
		return (ERROR_THREAD);
	return (SUCCESS);
}
int	join_threads(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	thread_index;

	thread_index = 0;
	while (thread_index < philo_datas->number_of_philos)
	{
		if (pthread_join(array_of_philos[thread_index]->philo, NULL) != 0)
		{
			return (ERROR_THREAD);
		}
		++thread_index;
	}
	return (SUCCESS);
}
