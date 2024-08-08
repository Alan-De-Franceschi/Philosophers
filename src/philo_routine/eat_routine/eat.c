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
	return (0);
}
