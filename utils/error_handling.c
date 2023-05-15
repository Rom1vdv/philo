/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:11 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/11 17:28:49 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handling(int error_type)
{
	if (error_type == ERROR_ARG_AMOUNT)
	{
		printf("Error : Wrong number of arguments.\n");
		return (ERROR_ARG_AMOUNT);
	}
	if (error_type == ERROR_ARG_VALIDITY)
	{
		printf("Error : Wrong type of arguments.\n");
		return (ERROR_ARG_VALIDITY);
	}
	if (error_type == ERROR_ALLOCATION)
	{
		printf("Error : Memory could not be allocated\n");
		return (ERROR_ALLOCATION);
	}
	if (error_type == ERROR_THREAD)
	{
		printf("Error : There was an issue with allocating the threads\n");
		return (ERROR_THREAD);
	}
	else
		return (SUCCESS);
}
