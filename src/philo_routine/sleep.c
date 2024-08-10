/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:58:01 by ade-fran          #+#    #+#             */
/*   Updated: 2024/07/25 14:58:03 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (ft_check_end(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		return (1);
	}
	printf(YELLOW "%ld " END "%d " BLUE "is sleeping\n" END,
		ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	if (ft_sleep_wait(philo) == 1)
		return (1);
	return (0);
}
