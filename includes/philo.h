/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:42:02 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/10 17:16:31 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include "structs.h"
# include "parsing.h"
# include "utils.h"
# include "init_philos.h"
# include "dining_philo_problem.h"

# define ALIVE true
# define DEAD false

#endif