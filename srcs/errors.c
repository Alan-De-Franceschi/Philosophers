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

int	ft_format_err(int index, char **argv)
{
	ft_putstr_fd(argv[index], 2);
	ft_putstr_fd(": non null numeric argument required", 2);
	return (EXIT_FAILURE);
}
