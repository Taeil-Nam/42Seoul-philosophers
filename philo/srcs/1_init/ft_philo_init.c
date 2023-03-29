/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:58 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/29 15:23:33 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_philo_vars(t_info *info, long count)
{
	info->philos[count]->philo_id = count + 1;
	info->philos[count]->info = info;
	info->philos[count]->left_fork = info->forks[count];
	if (info->philos[count]->philo_id == 1)
		info->philos[count]->right_fork = info->forks[info->num_of_philo - 1];
	else
		info->philos[count]->right_fork = info->forks[count - 1];
	info->philos[count]->left_fork_up = FALSE;
	info->philos[count]->right_fork_up = FALSE;
}

int	ft_philo_init(t_info *info)
{
	long	count;

	count = 0;
	info->philos
		= (t_philo **)malloc(sizeof(t_philo *) * (info->num_of_philo + 1));
	if (info->philos == NULL)
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->philos[count] = (t_philo *)malloc(sizeof(t_philo));
		if (info->philos[count] == NULL)
		{
			ft_free_philos(info->philos, count);
			ft_free_fork(info->forks, info->num_of_philo);
			return (FAILURE);
		}
		ft_set_philo_vars(info, count);
		count++;
	}
	if (count == 1)
		return (FAILURE);
	info->philos[count] = NULL;
	return (SUCCESS);
}
