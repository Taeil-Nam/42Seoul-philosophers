/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:05 by tnam              #+#    #+#             */
/*   Updated: 2023/03/29 10:51:12 by tnam             ###   ########.fr       */
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
		free(forks[i++]);
	free(forks);
}
