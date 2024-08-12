

#include "philo.h"

void    *ft_one_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    printf(YELLOW "%ld " END "%d " BLUE "has taken left fork\n" END,
		ft_print_time(philo), philo->id);
    usleep(philo->tdeath * 1000);
    pthread_mutex_unlock(philo->l_fork);
    return (NULL);
}
