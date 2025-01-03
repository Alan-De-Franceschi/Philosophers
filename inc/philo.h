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

/****************************************************************************/
/*                               Defines                                    */
/****************************************************************************/

# define GREEN 	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

/****************************************************************************/
/*                              Includes                                    */
/****************************************************************************/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

/****************************************************************************/
/*                              Structures                                  */
/****************************************************************************/

typedef struct s_philo
{
	pthread_t		tid;
	int				id;	
	int				tdeath;
	int				teat;
	int				tsleep;
	int				nb_philo;
	int				nb_eat;
	int				meals_eaten;
	int				finished;
	int				*go;
	long int		start_time;
	long int		*prog_start_time;
	long int		eat_time;
	int				*end;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*create_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*end_lock;
}	t_philo;

typedef struct s_program
{
	pthread_t		checker_tid;
	int				nb_philo;
	int				nb_thread;
	int				tdeath;
	int				teat;
	int				tsleep;
	int				nb_eat;
	int				finished_philo;
	int				end_flag;
	int				err;
	int				go;
	long int		start_time;
	pthread_mutex_t	*fork_lock;
	int				nb_fork;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	create_lock;
	t_philo			*philos;
}	t_program;

/****************************************************************************/
/*                             Init functions                               */
/****************************************************************************/

int			ft_init_data(t_program *data, char **argv);
t_philo		*ft_init_philos(t_program *data);

/****************************************************************************/
/*                            Philo routine                                 */
/****************************************************************************/

void		ft_philo(t_program *data);
void		ft_thread_creation_err(t_program *data);
void		ft_join_philos(t_program *data);
void		*ft_one_philo(t_philo *philo);
int			ft_global_routine(t_philo *philo);
int			ft_eat(t_philo *philo);
int			ft_even_philo_eat(t_philo *philo);
int			ft_odd_philo_eat(t_philo *philo);
int			ft_eat_wait(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			ft_sleep_wait(t_philo *philo);
int			ft_think(t_philo *philo);
int			ft_think_wait(t_philo *philo);
void		ft_wait_philos_start(t_program *data);
int			ft_check_end(t_philo *philo);
int			ft_death(t_program *data, t_philo *philo);
int			ft_end(t_program *data, t_philo *philo);

/****************************************************************************/
/*                            Time functions                                */
/****************************************************************************/

int			ft_init_start_time(t_program *data);
long int	ft_get_time(void);
long int	ft_print_time(t_philo *philo);

/****************************************************************************/
/*                                Free                                      */
/****************************************************************************/

void		ft_free_data(t_program *data);
void		ft_destroy_mlock(t_philo *philos, int nb_mlock);
void		ft_destroy_tlock(t_philo *philos, int nb_tlock);

/****************************************************************************/
/*                            Error management                              */
/****************************************************************************/

enum	e_errors
{
	FEW_ARGS	= 1,
	MANY_ARGS	= 2,
	WRONG_ARGS	= 3,
	THREAD_ERR	= 4,
	MUTEX_ERR	= 5,
};

int			ft_args_err(int err);
int			ft_format_err(t_program *data, int index, char **argv, int err);
void		ft_sys_err(int err);

/****************************************************************************/
/*                                Utils                                     */
/****************************************************************************/

int			ft_abs(int n);
int			ft_atoi(const char *nptr, int *error);
int			ft_putstr_fd(char *s, int fd);

#endif
