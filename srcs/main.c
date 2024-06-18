/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:02:42 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/31 11:02:49 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_args(int argc)
{
	if (argc < 5)
		return (ft_args_err(FEW_ARGS));
	if (argc > 6)
		return (ft_args_err(MANY_ARGS));
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_program	data;

	if (ft_check_args(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init_data(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//ft_philo(&data);
	return (EXIT_SUCCESS);
}
