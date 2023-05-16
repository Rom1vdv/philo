/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo_problem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:05:42 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/16 16:46:47 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	routine_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	routine_message(philo, "has taken a fork");
	routine_message(philo, "is eating");
	philo->last_meal = calculate_time();
	my_sleep(philo->datas->time_to_eat, philo->datas);
	pthread_mutex_lock(&philo->datas->mutex_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->datas->mutex_eat_count);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*run_process(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->philo_id % 2 == 0)
		my_sleep(philo->datas->time_to_eat / 2, philo->datas);
	philo->last_meal = calculate_time();
	while (1)
	{
		pthread_mutex_lock(&philo->datas->mutex_death_status);
		if (philo->datas->death_status == DEAD)
		{	
			pthread_mutex_unlock(&philo->datas->mutex_death_status);
			break ;
		}
		pthread_mutex_unlock(&philo->datas->mutex_death_status);
		philo_is_eating(philo);
		routine_message(philo, "is sleeping");
		my_sleep(philo->datas->time_to_sleep, philo->datas);
		routine_message(philo, "is thinking");
	}
	return (NULL);
}
