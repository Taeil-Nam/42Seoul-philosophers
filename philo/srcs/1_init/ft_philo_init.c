/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:58 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/27 21:35:41 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_init(t_info *info, t_philo **philos)
{
	long	count;

	count = 0;
	while (count < info->num_of_philo)
	{
		philos[count] = (t_philo *)malloc(sizeof(t_philo));
		if (philos[count] == NULL)
		{
			ft_free_philos(philos, count);
			return (FAILURE);
		}
		philos[count]->philo_num = count + 1;
		count++;
	}
	philos[count] = NULL;
	return (SUCCESS);
}
