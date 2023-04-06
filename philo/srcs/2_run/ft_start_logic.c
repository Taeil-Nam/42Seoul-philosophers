/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_logic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:33:08 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 17:37:44 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_create_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_create(&philos[philo_count]->thread, NULL,
				ft_routine, philos[philo_count]) != 0)
		{
			ft_free_philos(philos, info->num_of_philo);
			ft_free_forks(info->forks, info->num_of_philo);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

static int	ft_join_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_join(philos[philo_count]->thread, NULL) != 0)
		{
			ft_free_philos(philos, info->num_of_philo);
			ft_free_forks(info->forks, info->num_of_philo);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

int	ft_start_logic(t_info *info, t_philo **philos)
{
	if (pthread_mutex_init(&(info->die_mutex), NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&(info->finish_eat_mutex), NULL) != 0)
		return (FAILURE);
	if (ft_create_thread(info, philos) == FAILURE)
		return (FAILURE);
	if (ft_join_thread(info, philos) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
