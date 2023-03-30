/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/30 16:51:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_info *info, t_philo *philo)
{
	long	i;

	i = 0;
	printf("%ldms %ld dead\n",
				ft_current_time(philo->info), philo->philo_id);
	while (i < info->num_of_philo)
	{
		pthread_detach(info->philos[i]->thread);
		i++;
	}
	while (TRUE)
	{
		pthread_mutex_unlock(&(info->mutex));
		if (pthread_mutex_destroy(&(info->mutex)) == 0)
			break;
	}
	ft_free_forks(philo->info->forks, philo->info->num_of_philo);
	ft_free_philos(philo->info->philos, philo->info->num_of_philo);
	exit(EXIT_SUCCESS);
}
