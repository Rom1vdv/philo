/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:06:21 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/18 16:26:26 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->datas->mutex_death_status);
	philo->datas->death_status = DEAD;
	pthread_mutex_unlock(&philo->datas->mutex_death_status);
}

void	check_philo_status(t_philo **array_of_philo)
{
	int	thread_index;
	int	amount_of_time_eaten;

	while (1)
	{
		thread_index = 0;
		amount_of_time_eaten = 0;
		while (thread_index < array_of_philo[thread_index]->datas->number_of_philos)
		{
			pthread_mutex_lock(&array_of_philo[thread_index]->datas->mutex_last_meal);
			if (calculate_time() - array_of_philo[thread_index]->last_meal >= array_of_philo[thread_index]->datas->time_to_die)
			{
				routine_message(array_of_philo[thread_index], "died");
				pthread_mutex_unlock(&array_of_philo[thread_index]->datas->mutex_last_meal);
				return (check_death_status(array_of_philo[thread_index]));
			}
			pthread_mutex_unlock(&array_of_philo[thread_index]->datas->mutex_last_meal);
			pthread_mutex_lock(&array_of_philo[thread_index]->datas->mutex_eat_count);
			if (array_of_philo[thread_index]->eat_count > array_of_philo[thread_index]->datas->number_of_time_philo_ate && array_of_philo[thread_index]->datas->number_of_time_philo_ate != -1)
				++amount_of_time_eaten;
			pthread_mutex_unlock(&array_of_philo[thread_index]->datas->mutex_eat_count);	
		if (amount_of_time_eaten == array_of_philo[thread_index]->datas->number_of_philos)
			return (check_death_status(array_of_philo[thread_index]));
		}
		++thread_index;
	}
}
