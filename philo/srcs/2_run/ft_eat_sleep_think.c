/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/03/29 11:25:12 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_pick_fork(t_philo *philo)
{
	printf("%ldms %ld has taken a fork\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}

static int	ft_eat(t_philo *philo)
{
	ft_pick_fork(philo);
	if (philo->left_fork_up == TRUE || philo->right_fork_up == TRUE)
		printf("%ld %ld is eating\n",
			ft_current_time(philo->info), philo->philo_id);
	usleep(philo->info->time_to_eat * 1000);
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
