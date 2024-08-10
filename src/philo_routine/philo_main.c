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
	{
		if (ft_eat_wait(philo) == 1)
			return (NULL);
	}	
	while (1)
	{
		if (philo->meals_eaten > 0)
		{
			if (ft_think(philo) == 1)
				return (NULL);
		}
		if (ft_eat(philo) == 1)
			return (NULL);
		if (ft_sleep(philo) == 1)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}

static void	*ft_checker_routine(void *data)
{
	t_program	*program;
	int			i;

	program = (t_program *)data;
	while (1)
	{
		i = 0;
		while (i < program->nb_philo)
		{
			if (ft_end(program, &program->philos[i]) == 1)
				return (NULL);
			if (ft_death(program, &program->philos[i]) == 1)
				return (NULL);
			++i;
		}
		usleep(10);
	}
	return (NULL);
}

static void	ft_thread_create_err(t_program *data)
{
	data->err = THREAD_ERR;
	pthread_mutex_lock(&data->end_lock);
	data->end_flag = 1;
	pthread_mutex_unlock(&data->end_lock);
}

int	ft_philo(t_program *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_philo)
	{
		if (i == data->nb_philo)
			data->err = pthread_create(&data->checker_tid, NULL,
					ft_checker_routine, data);
		else
		{
			ft_init_start_time(&data->philos[i]);
			data->err = pthread_create(&data->philos[i].tid, NULL,
					ft_thread_routine, &data->philos[i]);
		}
		if (data->err)
		{
			ft_thread_create_err(data);
			break ;
		}
		++i;
		++data->nb_thread;
	}
	ft_join_philos(data);
	return (EXIT_SUCCESS);
}
