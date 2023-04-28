/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:35 by romvan-d          #+#    #+#             */
/*   Updated: 2023/04/27 16:58:32 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_datas(char **av, int ac, t_philo_datas *philo_datas)
{
	philo_datas->number_of_philos = ft_atoi();
	philo_datas->time_to_die = ft_atoi();
	philo_datas->time_to_eat = ft_atoi();
	philo_datas->time_to_sleep = ft_atoi();
	if (ac == 5)
		philo_datas->number_of_time_philo_eat = -1;
	else
		philo_datas->number_of_time_philo_eat = ft_atoi();
}

// void	init_philo(*t_philo philo)
// {
	
// }
int	main(int ac, char **av)
{	
	t_philo_datas *philo_datas;
	if (ac != 5 && ac != 6)
	{
		return (ERROR_ARG);
	}
	if (validate_input_args(av) == ERROR_ARG)
		return (ERROR_ARG);
	init_datas(av, philo_datas, ac)
	
}
