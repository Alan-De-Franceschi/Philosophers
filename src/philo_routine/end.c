/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:21:30 by ade-fran          #+#    #+#             */
/*   Updated: 2024/07/31 15:21:32 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_end(t_program *data, t_philo *philo)
{
	if (data->nb_eat != -1)
	{
		pthread_mutex_lock(&philo->meal_lock);
		if (philo->meals_eaten == data->nb_eat && philo->end == 0)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			philo->end = 1;
			++data->finished_philo;
			if (data->finished_philo == data->nb_philo)
			{
				pthread_mutex_lock(philo->write_lock);
				data->exit_flag = 1;
				printf("\033[0;32mThe %d philosophers ate their %d meals\033[0m\n", data->nb_philo, data->nb_eat);
				pthread_mutex_unlock(philo->write_lock);
				return (1);
			}
		}
		pthread_mutex_unlock(&philo->meal_lock);
	}
	return (0);
}
