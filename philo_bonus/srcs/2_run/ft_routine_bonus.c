/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 15:02:43 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_routine(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(((t_philo *)philo)->info->time_to_die / 4 * 1000);
	while (TRUE)
	{
		if (ft_eat(philo) == FAILURE)
			break ;
		if (ft_sleep(philo) == FAILURE)
			break ;
		if (ft_think(philo) == FAILURE)
			break ;
		if (((t_philo *)philo)->info->finish_eat_flag == TRUE)
			break ;
	}
	return (SUCCESS);
}