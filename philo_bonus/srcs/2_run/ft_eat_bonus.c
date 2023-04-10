/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/10 19:17:54 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_eating(long start_time, t_philo *philo)
{
	printf("%ld %ld is eating\n", ft_current_time(philo), philo->philo_id);
	while (ft_current_time(philo) < philo->simul)
		;
	philo->eat_count++;
	if (philo->eat_count == philo->must_eat_count)
	{
		free(philo->child);
		exit(FINISH_EAT);
	}
}

void	ft_eat(t_philo *philo)
{
	philo->simul = philo->simul + (ft_current_time(philo) - philo->simul);
	philo->simul = philo->simul + philo->time_to_eat;

	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken a fork\n", ft_current_time(philo), philo->philo_id);
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken a fork\n", ft_current_time(philo), philo->philo_id);

	sem_wait(philo->lock_philo);
	philo->last_eat_time = ft_current_time(philo);
	sem_post(philo->lock_philo);
	
	ft_eating(ft_current_time(philo), philo);
	sem_post(philo->fork_holder);
	sem_post(philo->fork_holder);
	
}
