/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 19:50:54 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_pick_left_fork(t_philo *philo)
{
	while (philo->left_fork->pickable == FALSE)
	{
		if (philo->info->time_to_die
			< ft_current_time(philo->info) - philo->last_eat_time)
		{
			ft_die(philo->info, philo);
			return (FAILURE);
		}
	}
	philo->left_fork_up = TRUE;
	philo->left_fork->pickable = FALSE;
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}

static int	ft_pick_right_fork(t_philo *philo)
{
	while (philo->right_fork->pickable == FALSE)
	{
		if (philo->info->time_to_die
			< ft_current_time(philo->info) - philo->last_eat_time)
		{
			ft_die(philo->info, philo);
			return (FAILURE);
		}
	}
	philo->right_fork_up = TRUE;
	philo->right_fork->pickable = FALSE;
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}

static int	ft_eating(long start_time, t_philo *philo)
{
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_eat)
	{
		if (philo->info->time_to_die
			< ft_current_time(philo->info) - philo->last_eat_time)
		{
			ft_die(philo->info, philo);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->mutex));
	if (ft_pick_left_fork(philo) != SUCCESS)
		return (FAILURE);
	if (ft_pick_right_fork(philo) != SUCCESS)
		return (FAILURE);
	pthread_mutex_unlock(&(philo->info->mutex));
	printf("%ldms %ld is eating\n",
		ft_current_time(philo->info), philo->philo_id);
	if (ft_eating(ft_current_time(philo->info), philo) != SUCCESS)
		return (FAILURE);
	philo->last_eat_time = ft_current_time(philo->info);
	philo->left_fork_up = FALSE;
	philo->left_fork->pickable = TRUE;
	philo->right_fork_up = FALSE;
	philo->right_fork->pickable = TRUE;
	return (SUCCESS);
}
