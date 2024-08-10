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
		if (philo->meals_eaten == data->nb_eat && philo->finished == 0)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			philo->finished = 1;
			++data->finished_philo;
			if (data->finished_philo == data->nb_philo)
			{
				pthread_mutex_lock(&data->end_lock);
				data->end_flag = 1;
				pthread_mutex_unlock(&data->end_lock);
				pthread_mutex_lock(&data->write_lock);
				printf("\033[0;32mThe %d philosophers ate their %d meals\033[0m\n",
					data->nb_philo, data->nb_eat);
				pthread_mutex_unlock(&data->write_lock);
				return (1);
			}
		}
		else
			pthread_mutex_unlock(&philo->meal_lock);
	}
	return (0);
}
