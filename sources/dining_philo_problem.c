/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo_problem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:05:42 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/10 17:17:38 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_process(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	while (philo->datas->is_dead == ALIVE)
	{
		
	}
}
