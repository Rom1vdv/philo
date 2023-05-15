/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:35 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 18:00:12 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_datas(char **av, int ac, t_philo_datas *philo_datas)
{
	philo_datas->number_of_philos = my_atoi(av[1]);
	philo_datas->time_to_die = my_atoi(av[2]);
	philo_datas->time_to_eat = my_atoi(av[3]);
	philo_datas->time_to_sleep = my_atoi(av[4]);
	philo_datas->forks = malloc(sizeof(philo_datas->forks) * philo_datas->number_of_philos);
	if (!philo_datas->forks)
		return (ERROR_ALLOCATION);
	philo_datas->death_status = ALIVE;
	if (ac == 5)
		philo_datas->number_of_time_philo_ate = -1;
	else
		philo_datas->number_of_time_philo_ate = my_atoi(av[5]);
	return (SUCCESS);
}

int	init_philos(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	i;
	int	init_philo_errors;

	i = 0;
	array_of_philos = malloc(sizeof(*array_of_philos)
			* philo_datas->number_of_philos);
	if (!array_of_philos)
		return (ERROR_ALLOCATION);
	init_philo_errors = create_threads(philo_datas, array_of_philos);
	if (init_philo_errors == ERROR_ALLOCATION)
		return (ERROR_ALLOCATION);
	if (init_philo_errors == ERROR_THREAD)
		return (ERROR_THREAD);
	init_philo_errors = join_threads(philo_datas, array_of_philos);
	if (init_philo_errors == ERROR_THREAD)
		return (ERROR_THREAD);
	return (SUCCESS);
}

int	main(int ac, char **av)
{	
	t_philo_datas	*philo_datas;
	t_philo			**array_of_philos;
	
	array_of_philos = NULL;
	philo_datas = malloc(sizeof(*philo_datas));
	if (ac != 5 && ac != 6)
		return (error_handling(ERROR_ARG_AMOUNT));
	if (validate_input_args(av) == ERROR_ARG_VALIDITY)
		return (error_handling(ERROR_ARG_VALIDITY));
	if (init_datas(av, ac, philo_datas) == ERROR_ALLOCATION)
		return (error_handling(ERROR_ALLOCATION));
	if (init_philos(philo_datas, array_of_philos) == ERROR_ALLOCATION)
		return (error_handling(ERROR_ALLOCATION));
	if (init_philos(philo_datas, array_of_philos) == ERROR_THREAD)
		return (error_handling(ERROR_THREAD));
	free(philo_datas->forks);
	return (SUCCESS);
}
