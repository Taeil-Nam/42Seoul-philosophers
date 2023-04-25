/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:29 by tnam              #+#    #+#             */
/*   Updated: 2023/04/25 11:00:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			free(info->eat_enough);
			return (FAILURE);
		}
		ft_set_fork_vars(info, count);
		count++;
	}
	info->forks[count] = NULL;
	return (SUCCESS);
}
