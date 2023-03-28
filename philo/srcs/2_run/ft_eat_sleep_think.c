/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 18:03:25 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_pick_fork(t_philo *philo)
{
	printf("%ldms %ld has taken a fork\n",
		ft_elapsed_time(philo->info->time_elapsed, 100, philo->info),
		philo->philo_id);
	return (SUCCESS);
}

static int	ft_eat(t_philo *philo)
{
	ft_pick_fork(philo);
	if (philo->left_fork_up == TRUE || philo->right_fork_up == TRUE)
		printf("%ldms %ld is eating\n",
			ft_elapsed_time(philo->info->time_elapsed, 200, philo->info),
			philo->philo_id);
	return (SUCCESS);
}

void	*ft_eat_sleep_think(void *philo)
{
	//eat
	ft_eat(philo);
	//sleep
	//think
	return (SUCCESS);
}
