/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:51:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/09 12:51:29 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mlock(t_philo *philos, int nb_mlock)
{
	int	i;

	i = 0;
	while (i < nb_mlock)
	{
		pthread_mutex_destroy(&philos[i].meal_lock);
		++i;
	}
	return ;
}

void	ft_destroy_tlock(t_philo *philos, int nb_tlock)
{
	int	i;

	i = 0;
	while (i < nb_tlock)
	{
		pthread_mutex_destroy(&philos[i].time_lock);
		++i;
	}
	return ;
}
