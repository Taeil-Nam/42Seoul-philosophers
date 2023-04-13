/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:14 by tnam              #+#    #+#             */
/*   Updated: 2023/04/13 14:41:10 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_sleeping(long start_time, t_philo *philo)
{
	printf("%ld %ld is sleeping\n", ft_current_time(philo), philo->philo_id);
	while (ft_current_time(philo) - start_time < philo->time_to_sleep)
		usleep(100);
}

void	ft_sleep(t_philo *philo)
{
	ft_sleeping(ft_current_time(philo), philo);
}
