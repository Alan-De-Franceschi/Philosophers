/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:53:02 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/08 11:53:06 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat_wait(t_philo *philo)
{
	int	count;

	count = 0;
	while (count < philo->teat)
	{
		usleep(100 * 1000);
		if (ft_check_end(philo) == 1)
			return (1);
		count += 100;
	}
	return (0);
}

int	ft_sleep_wait(t_philo *philo)
{
	int	count;

	count = 0;
	while (count < philo->tsleep)
	{
		usleep(100 * 1000);
		if (ft_check_end(philo) == 1)
			return (1);
		count += 100;
	}
	return (0);
}

int	ft_think_wait(t_philo *philo)
{
	int	count;
	int	time;

	count = 0;
	if (philo->tsleep <= philo->teat)
		time = philo->tsleep;
	else
		time = philo->teat;
	while (count < time)
	{
		usleep(100 * 1000);
		if (ft_check_end(philo) == 1)
			return (1);
		count += 100;
	}
	return (0);
}
