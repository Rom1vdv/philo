/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:35:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 12:30:21 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(int current_time, t_philo_datas *philo_datas)
{
	long	start_time;

	start_time = calculate_time();
	while (philo_datas->death_status == ALIVE)
	{
		if (calculate_time() - start_time >= current_time)
			break ;
		usleep(100);
	}
}
