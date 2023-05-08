/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:34:10 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/08 15:35:33 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "philo.h"

enum e_errors {
	SUCCESS = 0,
	ERROR_ARG = -1,
	ERROR_ALLOCATION = -2,
	ERROR_THREAD = -3,
};

typedef struct s_philo_datas
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_time_philo_eat;
	
}   t_philo_datas;

typedef struct s_philo
{
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t 		*philo;
	t_philo_datas	*datas;
}   t_philo;

#endif