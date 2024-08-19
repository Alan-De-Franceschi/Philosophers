/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:53 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/19 14:47:55 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_global_routine(t_philo *philo)
{
	if (philo->meals_eaten > 0)
	{
		if (ft_think(philo) == 1)
			return (1);
	}
	if (ft_eat(philo) == 1)
		return (1);
	if (ft_sleep(philo) == 1)
		return (1);
	return (0);
}
