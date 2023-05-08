/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:35 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/08 15:57:46 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_datas(char **av, int ac, t_philo_datas *philo_datas)
{
	philo_datas->number_of_philos = my_atoi(av[0]);
	philo_datas->time_to_die = my_atoi(av[1]);
	philo_datas->time_to_eat = my_atoi(av[2]);
	philo_datas->time_to_sleep = my_atoi(av[3]);
	if (ac == 5)
		philo_datas->number_of_time_philo_eat = -1;
	else
		philo_datas->number_of_time_philo_eat = my_atoi(av[4]);
}

int	init_philos(t_philo_datas *philo_datas, t_philo **array_of_philos)
{
	int	i;
	
	i = 0;
	array_of_philos = malloc(sizeof(*array_of_philos) * philo_datas->number_of_philos);
	if (array_of_philos == ERROR_ALLOCATION)
		return (ERROR_ALLOCATION);
	if (create_threads(philo_datas, *array_of_philos != 0))
		return (ERROR_THREAD);
	if (join_threads(philo_datas, *array_of_philos != 0))
		return (ERROR_THREAD);
}

int	main(int ac, char **av)
{	
	t_philo_datas philo_datas;
	t_philo_datas **array_of_philos;
	
	array_of_philos = NULL;
	if (ac != 5 && ac != 6)
	{
		printf("Error : Wrong number of arguments.\n");
		return (ERROR_ARG);
	}
	if (validate_input_args(av) == ERROR_ARG)
		printf("Error : The arguments you have entered are invalid.\n");
		return (ERROR_ARG);
	init_datas(av, ac, &philo_datas);
	if (init_philos(&philo_datas, array_of_philos) == ERROR_ALLOCATION)
		printf("Error : Memory could not be allocated");
		return (ERROR_ALLOCATION);
	if (init_philos(&philo_datas, array_of_philos) == ERROR_THREAD)
		printf("Error : There was an issue with allocating the threads");
		return (ERROR_THREAD);
	destroy_philos(array_of_philos);
	return (0);
	
}
