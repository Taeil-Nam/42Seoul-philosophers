/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/13 14:41:08 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_eating(long start_time, t_philo *philo)
{
	printf("%ld %ld is eating\n", ft_current_time(philo), philo->philo_id);
	while (ft_current_time(philo) - start_time < philo->time_to_eat)
		usleep(100);
	philo->eat_count++;
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken a fork\n",
		ft_current_time(philo), philo->philo_id);
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken a fork\n",
		ft_current_time(philo), philo->philo_id);
	sem_wait(philo->lock_philo);
	philo->last_eat_time = ft_current_time(philo);
	sem_post(philo->lock_philo);
	ft_eating(ft_current_time(philo), philo);
	sem_post(philo->fork_holder);
	sem_post(philo->fork_holder);
}
