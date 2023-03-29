/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:48:52 by tnam              #+#    #+#             */
/*   Updated: 2023/03/29 11:37:33 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_fork_vars(t_info *info, long count)
{
	info->forks[count]->fork_id = count + 1;
	info->forks[count]->info = info;
	info->forks[count]->pickable = TRUE;
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
