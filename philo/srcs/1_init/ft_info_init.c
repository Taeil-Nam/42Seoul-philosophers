/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:37 by tnam              #+#    #+#             */
/*   Updated: 2023/06/06 12:32:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_info_init(int argc, char *argv[], t_info *info)
{
	info->argc = argc;
	info->argv = argv;
	info->num_of_philo = ft_atol(argv[1]);
	info->time_to_die = ft_atol(argv[2]);
	info->time_to_eat = ft_atol(argv[3]);
	info->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
		info->must_eat_count = 0;
	else if (argc == 6)
		info->must_eat_count = ft_atol(argv[5]);
	info->die_flag = FALSE;
	info->finish_eat_flag = FALSE;
	info->first_die_time = -1;
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat_count < 0
		|| (info->argc == 6 && info->must_eat_count == 0))
		return (FAILURE);
	info->eat_enough = (long *)malloc(sizeof(long) * info->num_of_philo);
	if (info->eat_enough == NULL)
		return (FAILURE);
	memset(info->eat_enough, 0, info->num_of_philo);
	return (SUCCESS);
}
