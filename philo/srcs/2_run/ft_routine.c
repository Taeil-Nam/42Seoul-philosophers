/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:08 by tnam              #+#    #+#             */
/*   Updated: 2023/04/20 11:12:09 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (ft_check_finish_eat(philo) == TRUE)
			break ;
		if (ft_sleep(philo) == FAILURE)
			break ;
		if (ft_think(philo) == FAILURE)
			break ;
	}
	return (SUCCESS);
}
