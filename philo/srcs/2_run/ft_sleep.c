/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:13 by tnam              #+#    #+#             */
/*   Updated: 2023/05/08 20:27:01 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_sleeping(long start_time, t_philo *philo)
{
	ft_print(philo->info, philo->philo_id, "is sleeping\n");
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_sleep)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
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
