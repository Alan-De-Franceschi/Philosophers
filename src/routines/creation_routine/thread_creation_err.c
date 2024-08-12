

#include "philo.h"

void	ft_thread_creation_err(t_program *data)
{
	pthread_mutex_unlock(&data->create_lock);
	data->err = THREAD_ERR;
	pthread_mutex_lock(&data->end_lock);
	data->end_flag = 1;
	pthread_mutex_unlock(&data->end_lock);
    return ;
}
