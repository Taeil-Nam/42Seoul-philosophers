/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:14 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 23:16:45 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_sleeping(long start_time, t_philo *philo)
{
	printf("%ldms %ld is sleeping\n",
		ft_current_time(philo->info), philo->philo_id);
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_sleep)
	{
		if (ft_is_died(philo->info, philo) == TRUE
			|| ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_sleeping(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
