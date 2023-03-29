/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/03/29 12:49:07 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->mutex));
	while (philo->left_fork->pickable == FALSE)
		;
	philo->left_fork_up = TRUE;
	philo->left_fork->pickable = FALSE;
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	while (philo->right_fork->pickable == FALSE)
		;
	philo->right_fork_up = TRUE;
	philo->right_fork->pickable = FALSE;
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	pthread_mutex_unlock(&(philo->info->mutex));
}

static int	ft_eat(t_philo *philo)
{
	ft_pick_fork(philo);
	printf("%ldms %ld is eating\n",
		ft_current_time(philo->info), philo->philo_id);
	usleep(philo->info->time_to_eat * 1000);
	philo->left_fork_up = FALSE;
	philo->left_fork->pickable = TRUE;
	philo->right_fork_up = FALSE;
	philo->right_fork->pickable = TRUE;
	return (SUCCESS);
}

static int	ft_sleep(t_philo *philo)
{
	printf("%ldms %ld is sleeping\n",
		ft_current_time(philo->info), philo->philo_id);
	usleep(philo->info->time_to_sleep * 1000);
	return (SUCCESS);
}

static int	ft_think(t_philo *philo)
{
	printf("%ldms %ld is thinking\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}

void	*ft_eat_sleep_think(void *philo)
{
	while (TRUE)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (SUCCESS);
}
