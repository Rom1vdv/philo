/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:06:21 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/25 16:38:18 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->datas->mutex_death_status);
	philo->datas->death_status = DEAD;
	pthread_mutex_unlock(&philo->datas->mutex_death_status);
}

static void	check_eat_count(t_philo *philo, int *amount_of_time_eaten)
{
	pthread_mutex_lock(&philo->datas->mutex_eat_count);
	if (philo->eat_count
		> philo->datas->number_of_time_philo_ate
		&& philo->datas->number_of_time_philo_ate != -1)
		++(*amount_of_time_eaten);
	pthread_mutex_unlock(&philo->datas->mutex_eat_count);
}

void	check_philo_status(t_philo *philos)
{
	int	thread_i;
	int	amount_of_time_eaten;

	while (1)
	{
		thread_i = 0;
		amount_of_time_eaten = 0;
		while (thread_i < philos[thread_i].datas->number_of_philos)
		{
			pthread_mutex_lock(&philos[thread_i].datas->mutex_last_meal);
			if (calculate_time() - philos[thread_i].last_meal
				>= philos[thread_i].datas->time_to_die)
			{
				routine_message(&philos[thread_i], "died");
				pthread_mutex_unlock(&philos[thread_i].datas->mutex_last_meal);
				return (check_death_status(&philos[thread_i]));
			}
			pthread_mutex_unlock(&philos[thread_i].datas->mutex_last_meal);
			check_eat_count(&philos[thread_i], &amount_of_time_eaten);
			if (amount_of_time_eaten
				== philos[thread_i].datas->number_of_philos)
				return (check_death_status(&philos[thread_i]));
		}
		++thread_i;
	}
}
