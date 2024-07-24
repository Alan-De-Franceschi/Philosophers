/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:53:17 by ade-fran          #+#    #+#             */
/*   Updated: 2024/06/20 18:53:19 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_assign_forks(t_program *data, t_philo *philo, int nb_philos,
	int index)
{
	philo->l_fork = &data->fork_lock[index];
	if (index == 0)
		philo->r_fork = &data->fork_lock[nb_philos - 1];
	else
		philo->r_fork = &data->fork_lock[index - 1];
}

static void	ft_fill_philos(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		ft_assign_forks(data, &philos[i], data->nb_philo, i);
		philos[i].tdeath = data->tdeath;
		philos[i].teat = data->teat;
		philos[i].tsleep = data->tsleep;
		philos[i].nb_eat = data->nb_eat;
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].exit_lock = &data->exit_lock;
		philos[i].tid = 0;
		philos[i].id = 1 + i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = 0;
		philos[i].eat_time = 0;
		philos[i].dead = &data->dead_flag;
		philos[i].exit = &data->exit_flag;
		++i;
	}
}

t_philo	*ft_init_philos(t_program *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!philos)
		return (NULL);
	ft_fill_philos(philos, data);
	return (philos);
}