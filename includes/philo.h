/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:42:02 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/16 16:08:07 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include "structs.h"
# include "parsing.h"
# include "utils.h"
# include "init_philos.h"
# include "dining_philo_problem.h"
# include "death_status.h"

# define ALIVE 1
# define DEAD 0

#endif