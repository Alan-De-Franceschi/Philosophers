/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:30:20 by ade-fran          #+#    #+#             */
/*   Updated: 2024/07/25 14:30:23 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_even_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_death(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	printf("%ld %d has taken left fork\n", ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_death(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	printf("%ld %d has taken right fork\n", ft_print_time(philo), philo->id);
	printf("%ld %d is eating\n", ft_print_time(philo), philo->id);
	philo->eat_time = ft_get_time();
	++philo->meals_eaten;
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->teat * 1000);
	return (0);
}

static int	ft_odd_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_death(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	printf("%ld %d has taken right fork\n", ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_death(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	printf("%ld %d has taken left fork\n", ft_print_time(philo), philo->id);
	printf("%ld %d is eating\n", ft_print_time(philo), philo->id);
	philo->eat_time = ft_get_time();
	++philo->meals_eaten;
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->teat * 1000);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (ft_even_philo_eat(philo) == 1)
			return (1);
	}
	else
	{
		if (ft_odd_philo_eat(philo) == 1)
			return (1);
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}
