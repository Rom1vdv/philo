/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:35:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/15 14:23:47 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	destroy_philos(t_philo **array_of_philos);
int		my_atoi(const char *str);
long	calculate_time(void);
int		error_handling(int error_type);
void	my_sleep(int current_time, t_philo_datas *philo_datas);
void	routine_message(t_philo *philo, char *message);

#endif