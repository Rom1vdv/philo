/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:11 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:34:00 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_datas(t_philo_datas *philo_datas)
{
	int	i;

	i = 0;
	if (philo_datas)
	{
		if (philo_datas->forks)
		{
			while(i < philo_datas->number_of_philos)
			{
					
			}
			free(philo_datas->forks);
		}
		free(philo_datas);
	}
}

int	error_handling(int error_type, t_philo_datas *philos_datas,
	t_philo *array_of_philos)
{
	if (error_type == ERROR_ARG_AMOUNT)
		printf("Error : Wrong number of arguments.\n");
	if (error_type == ERROR_ARG_VALIDITY)
		printf("Error : Wrong type of arguments.\n");
	if (error_type == ERROR_ALLOCATION)
		printf("Error : Memory could not be allocated\n");
	if (error_type == ERROR_THREAD)
		printf("Error : There was an issue with allocating the threads\n");
	return (error_type);
}
