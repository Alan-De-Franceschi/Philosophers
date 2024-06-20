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
	printf("je suis le philosophe = %d, mon tid est : [%ld]\n", philo->id, philo->tid);
	return (NULL);
}

int	ft_philo(t_program *data)
{
	int 		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].tid, NULL, ft_thread_routine, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].tid, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
