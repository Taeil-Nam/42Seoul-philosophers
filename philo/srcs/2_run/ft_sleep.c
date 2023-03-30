/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:14 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 19:51:50 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_sleeping(long start_time, t_philo *philo)
{
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_sleep)
	{
		if (philo->info->time_to_die
			< ft_current_time(philo->info) - philo->last_eat_time)
		{
			ft_die(philo->info, philo);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	printf("%ldms %ld is sleeping\n",
		ft_current_time(philo->info), philo->philo_id);
	if (ft_sleeping(ft_current_time(philo->info), philo) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
