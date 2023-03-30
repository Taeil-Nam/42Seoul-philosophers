/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:41 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 23:16:06 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_died(t_info *info, t_philo *philo)
{
	long	die_time;

	if (info->time_to_die < ft_current_time(info) - philo->last_eat_time)
	{
		die_time = ft_current_time(info);
		info->die_flag = TRUE;
		while (ft_current_time(info) - die_time < 10)
			;
		printf("%ldms %ld is died\n", die_time, philo->philo_id);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_other_died(t_info *info)
{
	if (info->die_flag == TRUE)
		return (TRUE);
	return (FALSE);
}
