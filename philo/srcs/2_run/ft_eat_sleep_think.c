/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 19:08:48 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat_sleep_think(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(500);
	while (TRUE)
	{
		if (ft_eat(philo) != SUCCESS)
			break ;
		if (ft_sleep(philo) != SUCCESS)
			break ;
		if (ft_think(philo) != SUCCESS)
			break ;
	}
	return (SUCCESS);
}
