/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:02:04 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/11 12:09:37 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	calculate_time(void)
{
	long			accurate_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	accurate_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (accurate_time);
}
