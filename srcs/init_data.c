/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:54:49 by ade-fran          #+#    #+#             */
/*   Updated: 2024/06/05 16:54:52 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_args(t_program *data, char **argv)
{
	int	err;

	err = 0;
	data->nb_philo = ft_abs(ft_atoi(argv[1], &err));
	if (err || data->nb_philo == 0)
		return (ft_format_err(1, argv));
	data->tdeath = ft_abs(ft_atoi(argv[2], &err));
	if (err || data->tdeath == 0)
		return (ft_format_err(2, argv));
	data->teat = ft_abs(ft_atoi(argv[3], &err));
	if (err || data->teat == 0)
		return (ft_format_err(3, argv));
	data->tsleep = ft_abs(ft_atoi(argv[4], &err));
	if (err || data->tsleep == 0)
		return (ft_format_err(4, argv));
	if (argv[5])
	{
		data->nb_eat = ft_abs(ft_atoi(argv[5], &err));
		if (err || data->nb_eat == 0)
			return (ft_format_err(5, argv));
	}
	else
		data->nb_eat = -1;
	return (EXIT_SUCCESS);
}

static int	ft_init_mutex(t_program *data)
{
	int i;

	i = 0;
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
	if (!data->fork_lock)
		return (EXIT_FAILURE);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork_lock[i], NULL);
		++i;
	}
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	return (EXIT_SUCCESS);
}

static void	ft_fill_philos(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].nb_philo = data->nb_philo;
		philos[i].tdeath = data->tdeath;
		philos[i].teat = data->teat;
		philos[i].tsleep = data->tsleep;
		philos[i].nb_eat = data->nb_eat;
		philos[i].l_fork = NULL;
		philos[i].r_fork = NULL;
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].tid = 0;
		philos[i].id = 1 + i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = 0;
		philos[i].dead = &data->dead_flag;
		++i;
	}
}

static t_philo	*ft_init_philos(t_program *data)
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

int	ft_init_data(t_program *data, char **argv)
{
	if (ft_init_args(data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->philos  = ft_init_philos(data);
	if (!data->philos)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
