

#include "philo.h"

void    ft_wait_philos_start(t_program *data)
{
    while(1)
	{
		pthread_mutex_lock(&data->create_lock);
		if (data->go == data->nb_philo)
		{
			pthread_mutex_unlock(&data->create_lock);
			break ;
		}
		pthread_mutex_unlock(&data->create_lock);
		usleep(10);
	}
    return ;
}
