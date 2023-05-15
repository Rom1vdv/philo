/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/11 11:35:41 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philos(t_philo **array_of_philos)
{
	int	i;

	i = 0;
	while (array_of_philos[i])
	{
		free(array_of_philos[i]);
		++i;
	}
	free(array_of_philos);
}
