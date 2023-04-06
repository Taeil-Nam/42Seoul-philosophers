/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:41 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 16:56:00 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_finish_eat(t_philo *philo)
{
	long	count;

	usleep(100);
	pthread_mutex_lock(&(philo->info->finish_eat_mutex));
	count = 0;
	while (count < philo->info->num_of_philo)
	{
		if (philo->info->eat_enough[count] == FALSE)
		{
			pthread_mutex_unlock(&(philo->info->finish_eat_mutex));
			return (FALSE);
		}
		count++;
	}
	pthread_mutex_unlock(&(philo->info->finish_eat_mutex));
	return (TRUE);
}
