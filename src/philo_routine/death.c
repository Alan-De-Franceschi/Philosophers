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

int	ft_death(t_program *data, t_philo *philo)
{

	pthread_mutex_lock(&philo->meal_lock);
	int meal;
	meal = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_lock);
	if (meal == 0)
	{
		if (ft_get_time() - philo->start_time >= philo->tdeath)
		{
			pthread_mutex_lock(&data->write_lock);
			data->dead_flag = 1;
			printf("%ld %d died\n", ft_print_time(philo), philo->id);
			pthread_mutex_unlock(&data->write_lock);
			return (1);
		}
	}
	else if (meal > 0)
	{
		pthread_mutex_lock(&philo->time_lock);
		if (ft_get_time() - philo->eat_time >= philo->tdeath)
		{
			pthread_mutex_unlock(&philo->time_lock);
			pthread_mutex_lock(&data->write_lock);
			data->dead_flag = 1;
			printf("%ld %d died\n", ft_print_time(philo), philo->id);
			pthread_mutex_unlock(&data->write_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->time_lock);
	}
	return (0);
}
