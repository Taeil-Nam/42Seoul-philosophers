/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:05 by tnam              #+#    #+#             */
/*   Updated: 2023/04/05 19:54:51 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philos(t_philo **philos, long count)
{
	long	i;

	i = 0;
	while (i < count)
		free(philos[i++]);
	free(philos);
}

void	ft_free_forks(t_fork **forks, long count)
{
	long	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&(forks[i]->mutex));
		free(forks[i++]);
	}
	free(forks);
}
