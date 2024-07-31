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
	if (*philo->dead || *philo->exit)
	{
		pthread_mutex_unlock(philo->write_lock);
		return (1);
	}
	printf("\033[0;33m%ld\033[0m %d \033[0;36mis sleeping\033[0m\n", ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->tsleep * 1000);
	return (0);
}
