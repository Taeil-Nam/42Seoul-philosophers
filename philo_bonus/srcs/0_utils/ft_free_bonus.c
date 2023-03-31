/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:05 by tnam              #+#    #+#             */
/*   Updated: 2023/03/31 19:06:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		free(forks[i++]);
	free(forks);
}
