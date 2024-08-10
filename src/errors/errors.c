/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:00 by ade-fran          #+#    #+#             */
/*   Updated: 2024/06/05 17:18:06 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_args_err(int err)
{
	if (err == FEW_ARGS)
	{
		ft_putstr_fd("Too few arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (err == MANY_ARGS)
	{
		ft_putstr_fd("Too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_format_err(t_program *data, int index, char **argv, int err)
{
	ft_putstr_fd(argv[index], 2);
	if (err == WRONG_ARGS)
	{
		data->err = WRONG_ARGS;
		ft_putstr_fd(": non null numeric argument required", 2);
	}
	else if (err == NB_PHILOS)
	{
		data->err = NB_PHILOS;
		ft_putstr_fd(": nb philo must be numeric argument greater than 1", 2);
	}
	return (EXIT_FAILURE);
}

void	ft_sys_err(int err)
{
	if (err == THREAD_ERR)
		ft_putstr_fd("\033[0;31mpthread create : error\033[0m\n", 2);
	if (err == MUTEX_ERR)
		ft_putstr_fd("\033[0;31mmutex init : error\033[0m\n", 2);
	return ;
}
