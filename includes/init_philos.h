/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:16:46 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/23 18:08:06 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PHILOS_H
# define INIT_PHILOS_H
# include "philo.h"

int		create_threads(t_philo_datas *philo_datas, t_philo *array_of_philos);
int		join_threads(t_philo *array_of_philos, int thread_limit);
int		init_mutexes(t_philo_datas *philo_datas);

#endif