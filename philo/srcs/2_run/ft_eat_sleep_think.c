/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/04/05 19:55:02 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat_sleep_think(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(200 * 1000);


	while (TRUE)
	{
		//printf("ch %ld\n", ((t_philo *)philo)->info->first_die_time);
		if (((t_philo *)philo)->info->finish_eat_flag == TRUE)
			break ;
		if (ft_check_died(((t_philo *)philo)->info, ((t_philo *)philo)) == TRUE)
			break ;
		if (ft_eat(philo) == FAILURE)
			continue ;
		if (ft_sleep(philo) == FAILURE)
			continue ;
		if (ft_think(philo) == FAILURE)
			continue ;
	}
	return (SUCCESS);
}
