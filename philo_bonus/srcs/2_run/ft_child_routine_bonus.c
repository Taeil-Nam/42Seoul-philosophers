/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 15:02:43 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_child_routine(t_philo *philo)
{
	philo->last_eat_time = ft_current_time(philo);
	if (philo->philo_id % 2 == 1)
		usleep(philo->time_to_die / 4 * 1000);
	while (TRUE)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
