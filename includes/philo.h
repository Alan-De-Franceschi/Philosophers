/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:03:56 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/31 11:04:00 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_philo
{
	int				nb_philo;
	int				tdeath;
	int				teat;
	int				tsleep;
	int				nb_eat;
	pthread_t		tid;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				nb_philo;
	int				tdeath;
	int				teat;
	int				tsleep;
	int				nb_eat;
	int				dead_flag;
	pthread_mutex_t *fork_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_program;

int		ft_init_data(t_program *data, char **argv);
t_philo	*ft_init_philos(t_program *data);
int		ft_abs(int n);
int		ft_atoi(const char *nptr, int *error);
int		ft_putstr_fd(char *s, int fd);
int		ft_philo(t_program *data);

enum	e_errors
{
	FEW_ARGS = 0,
	MANY_ARGS = 1,
};

int		ft_args_err(int err);
int		ft_format_err(int index, char **argv);

#endif
