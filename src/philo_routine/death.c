/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:21:16 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/08 12:21:26 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_print_death(t_program *data, t_philo *philo)
{
	pthread_mutex_lock(&data->end_lock);
	data->end_flag = 1;
	pthread_mutex_unlock(&data->end_lock);
	pthread_mutex_lock(&data->write_lock);
	printf(RED "%ld %d died\n" END,
		ft_print_time(philo), philo->id);
	pthread_mutex_unlock(&data->write_lock);
	return (1);
}

int	ft_death(t_program *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->meals_eaten == 0)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		if (ft_get_time() - philo->start_time >= philo->tdeath)
			return (ft_print_death(data, philo));
	}
	else if (philo->meals_eaten > 0)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		pthread_mutex_lock(&philo->time_lock);
		if (ft_get_time() - philo->eat_time >= philo->tdeath)
		{
			pthread_mutex_unlock(&philo->time_lock);
			return (ft_print_death(data, philo));
		}
		pthread_mutex_unlock(&philo->time_lock);
	}
	else
		pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}
