/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/10 15:28:02 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_eating(long start_time, t_philo *philo)
{
	printf("%ld %ld is eating\n", ft_current_time(philo), philo->philo_id);
	while (ft_current_time(philo) - start_time < philo->time_to_eat)
		if (ft_current_time(philo) - philo->last_eat_time >= philo->time_to_die)
			exit (STARVED);
	philo->eat_count++;
	if (philo->eat_count == philo->must_eat_count)
		exit(FINISH_EAT);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->fork_holder);

	printf("%ld %ld has taken fork\n", ft_current_time(philo), philo->philo_id);
	sem_wait(philo->fork_holder);
	printf("%ld %ld has taken fork\n", ft_current_time(philo), philo->philo_id);
	philo->last_eat_time = ft_current_time(philo);
	ft_eating(ft_current_time(philo), philo);
	sem_post(philo->fork_holder);
	sem_post(philo->fork_holder);
}

void *monitoring(t_philo *a)
{
	while (a->1)
	{
		if (1231)
			exit(1);
		else if (13124)
			exit()
	}
}