/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 16:45:26 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_pick_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	if (philo->right_fork->pickable == TRUE)
	{
		philo->right_fork->pickable = FALSE;
		philo->right_fork_up = TRUE;
		printf("%ld %ld has taken a fork\n",
			ft_current_time(philo->info), philo->philo_id);
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (FAILURE);
	}
}

static int	ft_pick_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	if (philo->left_fork->pickable == TRUE)
	{
		philo->left_fork->pickable = FALSE;
		philo->left_fork_up = TRUE;
		printf("%ld %ld has taken a fork\n",
			ft_current_time(philo->info), philo->philo_id);
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (FAILURE);
	}
}

static int	ft_put_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	philo->right_fork_up = FALSE;
	philo->right_fork->pickable = TRUE;
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo->left_fork_up = FALSE;
	philo->left_fork->pickable = TRUE;
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	return (SUCCESS);
}

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
	if (philo->eat_count >= philo->info->must_eat_count)
		philo->info->eat_enough[philo->philo_id - 1] = TRUE;
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	while (ft_pick_right_fork(philo) == FAILURE)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
			return (FAILURE);
	}
	while (ft_pick_left_fork(philo) == FAILURE)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
			return (FAILURE);
	}
	philo->last_eat_time = ft_current_time(philo->info);
	if (ft_eating(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	ft_put_fork(philo);
	return (SUCCESS);
}
