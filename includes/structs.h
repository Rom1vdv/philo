/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:34:10 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 18:50:06 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "philo.h"

enum e_errors {
	SUCCESS = 0,
	ERROR_ARG_AMOUNT = -1,
	ERROR_ARG_VALIDITY = -2,
	ERROR_ALLOCATION = -3,
	ERROR_THREAD = -4,
};

typedef struct s_philo_datas
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_philo_ate;
	int				death_status;
	pthread_mutex_t mutex_death_status;
	long			start_time;
	pthread_mutex_t *forks;
}	t_philo_datas;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t message;
	t_philo_datas	*datas;
	pthread_t		philo;
	int				eat_count;
	int				philo_id;
	long			last_meal;
}	t_philo;

#endif