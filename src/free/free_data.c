/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:59:23 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/08 13:59:25 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_free_forks(pthread_mutex_t	*fork_lock, int nb_fork)
{
	int	i;

	i = 0;
	while (i < nb_fork)
	{
		pthread_mutex_destroy(&fork_lock[i]);
		++i;
	}
	free(fork_lock);
}

static void	ft_free_philos(t_philo *philos, int nb_thread, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_thread)
	{
		if (i == nb_philo)
			break ;
		pthread_mutex_destroy(&philos[i].meal_lock);
		pthread_mutex_destroy(&philos[i].time_lock);
		++i;
	}
	free(philos);
}

void	ft_free_data(t_program *data)
{
	if (data->err)
	{
		if (data->err == WRONG_ARGS)
		{
			data->err = 1;
			return ;
		}
		ft_sys_err(data->err);
		data->err = 1;
	}
	ft_free_forks(data->fork_lock, data->nb_fork);
	ft_free_philos(data->philos, data->nb_thread, data->nb_philo);
}
