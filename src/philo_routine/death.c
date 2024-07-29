/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:33:26 by ade-fran          #+#    #+#             */
/*   Updated: 2024/07/25 17:33:27 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	else if (philo->meals_eaten == 0)
	{
		if (ft_get_time() - philo->start_time >= philo->tdeath)
		{
			*philo->dead = 1;
			printf("%ld %d died\n", ft_print_time(philo), philo->id);
			pthread_mutex_unlock(philo->dead_lock);
			return (1);
		}
	}
	else if (philo->meals_eaten > 0)
	{
		if (ft_get_time() - philo->eat_time >= philo->tdeath)
		{
			*philo->dead = 1;
			printf("%ld %d died\n", ft_print_time(philo), philo->id);
			pthread_mutex_unlock(philo->dead_lock);
			return (1);
		}
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
