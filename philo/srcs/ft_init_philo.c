/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:07:58 by tnam              #+#    #+#             */
/*   Updated: 2023/03/24 19:45:23 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_info *info, t_philo **philos)
{
	long	count;

	philos = (t_philo **)malloc(sizeof(t_philo *) * (info->num_of_philo + 1));
	if (philos == NULL)
		exit(EXIT_FAILURE);
	count = 0;
	while (count < info->num_of_philo)
	{
		philos[count] = (t_philo *)malloc(sizeof(t_philo));
		if (philos[count] == NULL)
			ft_free_philos(philos, count);
		philos[count]->philo_num = count + 1;
		philos[count]->fork_count = 0;
		count++;
	}
}
