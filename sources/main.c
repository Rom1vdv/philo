/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:35 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/18 16:42:19 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_datas(char **av, int ac, t_philo_datas *philo_datas)
{
	philo_datas->number_of_philos = my_atoi(av[1]);
	philo_datas->time_to_die = my_atoi(av[2]);
	philo_datas->time_to_eat = my_atoi(av[3]);
	philo_datas->time_to_sleep = my_atoi(av[4]);
	philo_datas->forks = malloc(sizeof(*philo_datas->forks)
			* philo_datas->number_of_philos);
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
	init_philo_errors = init_mutexes(philo_datas);
	if (init_philo_errors == ERROR_THREAD)
		return (init_philo_errors);
	init_philo_errors = create_threads(philo_datas, array_of_philos);
	if (init_philo_errors == ERROR_ALLOCATION)
		return (init_philo_errors);
	if (init_philo_errors == ERROR_THREAD)
		return (init_philo_errors);
	check_philo_status(array_of_philos);
	init_philo_errors = join_threads(philo_datas, array_of_philos);
	if (init_philo_errors == ERROR_THREAD)
		return (init_philo_errors);
	return (SUCCESS);
}

int	main(int ac, char **av)
{	
	t_philo_datas	*philo_datas;
	t_philo			**array_of_philos;
	int				error_status;

	if (ac != 5 && ac != 6)
		return (error_handling(ERROR_ARG_AMOUNT));
	array_of_philos = NULL;
	philo_datas = malloc(sizeof(*philo_datas));
	error_status = validate_input_args(av);
	if (error_status == ERROR_ARG_VALIDITY)
		return (error_handling(error_status));
	error_status = init_datas(av, ac, philo_datas);
	if (error_status == ERROR_ALLOCATION)
		return (error_handling(error_status));
	error_status = init_philos(philo_datas, array_of_philos);
	if (error_status == ERROR_ALLOCATION)
		return (error_handling(error_status));
	if (error_status == ERROR_THREAD)
		return (error_handling(error_status));
	destroy_mutexes(philo_datas);
	destroy_philos(array_of_philos);
	return (SUCCESS);
}
