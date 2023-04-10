/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:14 by tnam              #+#    #+#             */
/*   Updated: 2023/04/10 19:15:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_sleeping(long start_time, t_philo *philo)
{
	printf("%ld %ld is sleeping\n", ft_current_time(philo), philo->philo_id);
	while (ft_current_time(philo) < philo->simul)
		;
}

void	ft_sleep(t_philo *philo)
{
	philo->simul = philo->simul + philo->time_to_sleep;
	ft_sleeping(ft_current_time(philo), philo);
}
