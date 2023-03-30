/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:27 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 23:17:10 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_pick_left_fork(t_philo *philo)
{
	while (philo->left_fork->pickable == FALSE)
	{
		if (ft_is_died(philo->info, philo) == TRUE
			|| ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
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
		if (ft_is_died(philo->info, philo) == TRUE
			|| ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
	}
	philo->right_fork_up = TRUE;
	philo->right_fork->pickable = FALSE;
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}

static int	ft_eating(long start_time, t_philo *philo)
{
	printf("%ldms %ld is eating\n",
		ft_current_time(philo->info), philo->philo_id);
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_eat)
	{
		if (ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->mutex));
	if (ft_pick_left_fork(philo) == FAILURE)
		return (FAILURE);
	if (ft_pick_right_fork(philo) == FAILURE)
		return (FAILURE);
	pthread_mutex_unlock(&(philo->info->mutex));
	if (ft_eating(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	philo->last_eat_time = ft_current_time(philo->info);
	philo->left_fork_up = FALSE;
	philo->left_fork->pickable = TRUE;
	philo->right_fork_up = FALSE;
	philo->right_fork->pickable = TRUE;
	return (SUCCESS);
}
