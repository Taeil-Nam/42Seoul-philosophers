/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:31:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/30 18:08:12 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_argv_init(int argc, char *argv[], t_info *info)
{
	info->argc = argc;
	info->argv = argv;
	if (argc == 5)
	{
		info->num_of_philo = ft_atol(argv[1]);
		info->time_to_die = ft_atol(argv[2]);
		info->time_to_eat = ft_atol(argv[3]);
		info->time_to_sleep = ft_atol(argv[4]);
		info->must_eat_count = 0;
	}
	else if (argc == 6)
	{
		info->num_of_philo = ft_atol(argv[1]);
		info->time_to_die = ft_atol(argv[2]);
		info->time_to_eat = ft_atol(argv[3]);
		info->time_to_sleep = ft_atol(argv[4]);
		info->must_eat_count = ft_atol(argv[5]);
	}
	if (info->num_of_philo <= 1 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat_count < 0)
		return (FAILURE);
	return (SUCCESS);
}
