/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:35:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/08 15:57:30 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

size_t	ft_strlen(char *string);
void	destroy_philos(t_philo **array_of_philos);
int		my_atoi(const char *str);
long	calculate_time(void);

#endif