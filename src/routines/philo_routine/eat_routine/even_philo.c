/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:24:03 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/08 13:24:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_rfork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_check_end(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	printf(YELLOW "%ld " END "%d " BLUE "has taken right fork\n" END,
		ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

static int	ft_lfork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	if (ft_check_end(philo) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	printf(YELLOW "%ld " END "%d " BLUE "has taken left fork\n" END,
		ft_print_time(philo), philo->id);
	printf(YELLOW "%ld " END "%d " BLUE "is eating\n" END,
		ft_print_time(philo), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

static int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->time_lock);
	philo->eat_time = ft_get_time();
	pthread_mutex_unlock(&philo->time_lock);
	if (ft_eat_wait(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->meal_lock);
	++philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	ft_even_philo_eat(t_philo *philo)
{
	if (ft_rfork(philo) == 1)
		return (1);
	if (ft_lfork(philo) == 1)
		return (1);
	if (ft_eating(philo) == 1)
		return (1);
	return (0);
}
