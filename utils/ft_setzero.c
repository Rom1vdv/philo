/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:52:46 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:25:56 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_setzero(void *p, size_t len)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) p;
	i = 0;
	while (len > 0)
	{
		ptr[i] = 0;
		i++;
		len --;
	}
	return (p);
}
