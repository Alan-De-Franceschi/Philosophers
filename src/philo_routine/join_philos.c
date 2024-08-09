/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:30:41 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/09 15:30:44 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_philos(t_program *data)
{
	int	i;

	i = 0;
	while (i < data->nb_thread)
	{
		if (i == data->nb_philo)
			pthread_join(data->checker_tid, NULL);
		else
			pthread_join(data->philos[i].tid, NULL);
		++i;
	}
	return ;
}
