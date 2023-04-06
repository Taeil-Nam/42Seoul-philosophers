/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:41 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 14:51:49 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_died(t_info *info, t_philo *philo)
{
	long	die_time;

	usleep(100);
	pthread_mutex_lock(&(info->mutex));
	if (info->die_flag == TRUE)
	{
		pthread_mutex_unlock(&(info->mutex));
		return (TRUE);
	}
	if (info->time_to_die < ft_current_time(info) - philo->last_eat_time)
	{
		die_time = ft_current_time(info);
		info->die_flag = TRUE;
		while (ft_current_time(info) - die_time < 10)
			;
		if (info->first_die_time == -1)
		{
			printf("%ld %ld died\n", die_time, philo->philo_id);
			info->first_die_time = die_time;
		}
		pthread_mutex_unlock(&(info->mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->mutex));
	return (FALSE);
}

int	ft_is_other_died(t_info *info)
{
	usleep(100);
	pthread_mutex_lock(&(info->mutex));
	if (info->die_flag == TRUE)
	{
		pthread_mutex_unlock(&(info->mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->mutex));
	return (FALSE);
}

int	ft_check_died(t_info *info, t_philo *philo)
{
	if (ft_is_died(info, philo) == TRUE || ft_is_other_died(info) == TRUE)
		return (TRUE);
	return (FALSE);
}
