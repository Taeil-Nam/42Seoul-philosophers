/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:32:58 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/28 11:58:16 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_init(t_info *info)
{
	long	count;

	count = 0;
	info->philos
		= (t_philo **)malloc(sizeof(t_philo *) * (info->num_of_philo + 1));
	if (info->philos == NULL)
		return (EXIT_FAILURE);
	while (count < info->num_of_philo)
	{
		info->philos[count] = (t_philo *)malloc(sizeof(t_philo));
		if (info->philos[count] == NULL)
		{
			ft_free_philos(info->philos, count);
			return (FAILURE);
		}
		info->philos[count]->philo_num = count + 1;
		count++;
	}
	info->philos[count] = NULL;
	return (SUCCESS);
}
