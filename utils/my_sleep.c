/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:35:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/18 14:41:19 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(int current_time, t_philo_datas *philo_datas)
{
	long		start_time;

	start_time = calculate_time();
	while (1)
	{
		pthread_mutex_lock(&philo_datas->mutex_death_status);
		if (philo_datas->death_status == DEAD)
		{	
			pthread_mutex_unlock(&philo_datas->mutex_death_status);
			break ;
		}
		pthread_mutex_unlock(&philo_datas->mutex_death_status);
		if (calculate_time() - start_time >= current_time)
			break ;
		usleep(100);
	}
}
