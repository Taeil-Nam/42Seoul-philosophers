/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:31:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/06 16:40:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat_count < 0
		|| (info->argc == 6 && info->must_eat_count == 0))
		return (FAILURE);
	return (SUCCESS);
}
