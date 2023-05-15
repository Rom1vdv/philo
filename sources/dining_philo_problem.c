/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo_problem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:05:42 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 18:00:26 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	routine_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork);
	routine_message(philo, "has taken a fork");
	routine_message(philo, "is eating");
	philo->eat_count++;
	philo->last_meal = calculate_time();
	my_sleep(philo->datas->time_to_eat, philo->datas);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

int	check_if_philo_died(t_philo *philo)
{
	if (calculate_time() - philo->last_meal >= philo->datas->time_to_die)
	{
		pthread_mutex_lock(&philo->datas->mutex_death_status);
		philo->datas->death_status = DEAD;
		routine_message(philo, "died");
		pthread_mutex_unlock(&philo->datas->mutex_death_status);
		return (1);
	}
	return (0);
}

int	check_if_philo_has_eaten(t_philo *philo)
{
	if (philo->eat_count == philo->datas->number_of_time_philo_ate)
		return (1);
	return (0);
}

void	*run_process(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *) arg;
	if (philo->philo_id % 2 == 0)
		my_sleep(philo->datas->time_to_eat / 2, philo->datas);
	philo->last_meal = calculate_time();
	while (philo->datas->death_status == ALIVE)
	{
		if (check_if_philo_died(philo) == 1)
			break ;
		if (check_if_philo_has_eaten(philo) == 1)
			break ;
		philo_is_eating(philo);
		routine_message(philo, "is sleeping");
		my_sleep(philo->datas->time_to_sleep, philo->datas);
		routine_message(philo, "is thinking");
	}
	return (NULL);
}
