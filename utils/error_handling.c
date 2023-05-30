/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:11 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/30 15:26:05 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_allocation_error(t_philo_datas *philo_datas,
	t_philo *array_of_philos, int mode)
{
	if (mode == 1)
	{
		free(philo_datas);
		printf("Error : Memory could not be allocated\n");
	}
	else if (mode == 2)
	{
		free(philo_datas->forks);
		free(philo_datas);
		printf("Error : Memory could not be allocated\n");
	}
	else if (mode == 3)
	{
		free(philo_datas->forks);
		free(philo_datas);
		free(array_of_philos);
		printf("Error : Memory could not be allocated\n");
	}
	return (SUCCESS);
}

static int	handle_thread_error(t_philo_datas *philo_datas,
	t_philo *array_of_philos, int mode)
{
	if (mode == 3)
	{
		destroy_mutexes(philo_datas);
		free(philo_datas->forks);
		free(philo_datas);
		free(array_of_philos);
		printf("Error : There was an issue with allocating the threads\n");
	}
	return (SUCCESS);
}

int	error_handling(int error_type, t_philo_datas *philo_datas,
	t_philo **array_of_philos, int mode)
{
	if (error_type == ERROR_ARG_AMOUNT && mode == 0)
		printf("Error : Wrong number of arguments.\n");
	if (error_type == ERROR_ARG_VALIDITY && mode == 0)
		printf("Error : Wrong type of arguments.\n");
	if (error_type == ERROR_ALLOCATION && mode == 1)
		return (handle_allocation_error(philo_datas, *array_of_philos, 1));
	if (error_type == ERROR_ALLOCATION && mode == 2)
		return (handle_allocation_error(philo_datas, *array_of_philos, 2));
	if (error_type == ERROR_ALLOCATION && mode == 3)
		return (handle_allocation_error(philo_datas, *array_of_philos, 3));
	if (error_type == ERROR_THREAD && mode == 3)
		return (handle_thread_error(philo_datas, *array_of_philos, 3));
	return (error_type);
}
