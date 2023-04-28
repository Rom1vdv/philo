/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:42:02 by romvan-d          #+#    #+#             */
/*   Updated: 2023/04/27 16:57:32 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include "parsing.h"
# include "utils.h"

enum e_errors {
	SUCCESS = 0,
	ERROR_ARG = 1,
};

typedef struct s_philo_datas
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_time_philo_eat;
	
}   t_philo_datas;

// typedef struct s_philo
// {
	
// }   t_philo;



#endif