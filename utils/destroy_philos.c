/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/30 13:26:24 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philos(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	free(philo_datas->forks);
	free(philo_datas);
	free(*array_of_philos);
}

void	destroy_mutexes(t_philo_datas *philo_datas)
{
	int	i;

	i = 0;
	while (i < philo_datas->number_of_philos)
	{
		pthread_mutex_destroy(&philo_datas->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&philo_datas->mutex_eat_count);
	pthread_mutex_destroy(&philo_datas->message);
	pthread_mutex_destroy(&philo_datas->mutex_death_status);
	pthread_mutex_destroy(&philo_datas->mutex_last_meal);
	return ;
}
