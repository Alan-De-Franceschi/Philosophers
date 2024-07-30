/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:37:52 by ade-fran          #+#    #+#             */
/*   Updated: 2024/07/25 15:37:54 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (*philo->dead)
	{
		pthread_mutex_unlock(philo->write_lock);
		return (1);
	}
	printf("%ld %d is thinking\n", ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}
