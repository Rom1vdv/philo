/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:24:37 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 18:29:31 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->datas->mutex_death_status);
	if (philo->datas->death_status == ALIVE)
	{
		pthread_mutex_lock(&philo->message);
		printf("%lu %d %s \n", calculate_time() - philo->datas->start_time , philo->philo_id, message);
		pthread_mutex_unlock(&philo->message);
	}
	pthread_mutex_unlock(&philo->datas->mutex_death_status);
}