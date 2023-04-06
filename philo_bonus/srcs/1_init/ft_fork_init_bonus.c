/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:48:52 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 16:40:36 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_set_fork_vars(t_info *info, long count)
{
	info->forks[count]->fork_id = count + 1;
	info->forks[count]->info = info;
	info->forks[count]->pickable = TRUE;
	pthread_mutex_init(&(info->forks[count]->mutex), NULL);
}

int	ft_fork_init(t_info *info)
{
	long	count;

	count = 0;
	info->forks
		= (t_fork **)malloc(sizeof(t_fork *) * (info->num_of_philo + 1));
	if (info->forks == NULL)
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->forks[count] = (t_fork *)malloc(sizeof(t_fork));
		if (info->forks[count] == NULL)
		{
			ft_free_forks(info->forks, count);
			return (FAILURE);
		}
		ft_set_fork_vars(info, count);
		count++;
	}
	info->forks[count] = NULL;
	return (SUCCESS);
}
