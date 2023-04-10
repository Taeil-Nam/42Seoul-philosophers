/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/10 13:19:08 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_eating(long start_time, t_philo *philo)
{
	printf("%ld %ld is eating\n",
		ft_current_time(philo->info), philo->philo_id);
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_eat)
	{
		if (ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
	}
	philo->eat_count++;
	if (ft_check_finish_eat(philo) == TRUE)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken fork\n",
		ft_current_time(philo->info), philo->philo_id);
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken fork\n",
		ft_current_time(philo->info), philo->philo_id);
	philo->last_eat_time = ft_current_time(philo->info);
	if (ft_eating(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	sem_post(philo->fork_holder);
	sem_post(philo->fork_holder);
	return (SUCCESS);
}
