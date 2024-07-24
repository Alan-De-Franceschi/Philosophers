/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:13:23 by ade-fran          #+#    #+#             */
/*   Updated: 2024/06/05 22:13:24 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_thread_routine(void *data)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)data;
	i = 0;
	while (philo->meals_eaten < philo->nb_eat)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->l_fork);
			pthread_mutex_lock(philo->write_lock);
			printf("%ld %d has taken left fork\n", ft_get_time(), philo->id);
			pthread_mutex_unlock(philo->write_lock);
			pthread_mutex_lock(philo->r_fork);
			pthread_mutex_lock(philo->write_lock);
			printf("%ld %d has taken right fork\n", ft_get_time(), philo->id);
			printf("%ld %d is eating\n", ft_get_time(), philo->id);
			pthread_mutex_unlock(philo->write_lock);
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			pthread_mutex_lock(philo->write_lock);
			printf("%ld %d has taken right fork\n", ft_get_time(), philo->id);
			pthread_mutex_unlock(philo->write_lock);
			pthread_mutex_lock(philo->l_fork);
			pthread_mutex_lock(philo->write_lock);
			printf("%ld %d has taken left fork\n", ft_get_time(), philo->id);
			printf("%ld %d is eating\n", ft_get_time(), philo->id);
			pthread_mutex_unlock(philo->write_lock);
		}
		pthread_mutex_lock(philo->meal_lock);
		++philo->meals_eaten;
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		
	}
	return (NULL);
}

int	ft_philo(t_program *data)
{
	int 		i;
	int			j;

	i = 0;
	j = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].tid, NULL, ft_thread_routine, &data->philos[i]);
		if (ft_init_start_time(&data->philos[i]) == EXIT_FAILURE)
		{
			pthread_mutex_lock(&data->exit_lock);
			data->exit_flag = 1;
			pthread_mutex_unlock(&data->exit_lock);
			break;
		}
		++i;
	}
	while (j <= i && j < data->nb_philo)
	{
		pthread_join(data->philos[j].tid, NULL);
		++j;
	}
	return (EXIT_SUCCESS);
}
