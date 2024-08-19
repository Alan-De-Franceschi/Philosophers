/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:26:36 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/19 14:26:39 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_philos_start(t_program *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->create_lock);
		if (data->go == data->nb_philo)
		{
			pthread_mutex_unlock(&data->create_lock);
			break ;
		}
		pthread_mutex_unlock(&data->create_lock);
		usleep(10);
	}
}
