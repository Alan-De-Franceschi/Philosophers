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

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
			usleep(philo->teat * 1000);
	while (philo->meals_eaten != philo->nb_eat)
	{
		if (ft_think(philo) == 1)
			return (NULL);
		if (ft_eat(philo) == 1)
			return (NULL);
		if (philo->meals_eaten != philo->nb_eat)
		{
			if (ft_sleep(philo) == 1)
				return (NULL);
		}
	}
	return (NULL);
}

static void	*ft_checker_routine(void *data)
{
	t_program	*program;
	int i;

	program = (t_program *)data;
	while (1)
	{
		i = 0;
		while (i < program->nb_philo)
		{
			if (ft_death(program, &program->philos[i]) == 1)
				return (NULL);
			++i;
		}
		usleep(50);
	}
	return (NULL);
}

int	ft_philo(t_program *data)
{
	int 		i;

	i = 0;
	while (i <= data->nb_philo)
	{
		if (i == data->nb_philo)
			pthread_create(&data->checker_tid, NULL, ft_checker_routine, data);
		else
		{
			ft_init_start_time(&data->philos[i]);
			pthread_create(&data->philos[i].tid, NULL, ft_thread_routine, &data->philos[i]);
		}
		++i;
	}
	i = 0;
	while (i <= data->nb_philo)
	{
		if (i == data->nb_philo)
			pthread_join(data->checker_tid, NULL);
		else
			pthread_join(data->philos[i].tid, NULL);
		++i;
	}
	return (EXIT_SUCCESS);
}
