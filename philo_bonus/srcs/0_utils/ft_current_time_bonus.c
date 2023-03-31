/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:55 by tnam              #+#    #+#             */
/*   Updated: 2023/03/31 19:06:05 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_current_time(t_info *info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - info->time_booted);
}

long	ft_elapsed_time(long start_ms, long end_ms, t_info *info)
{
	while (ft_current_time(info) - start_ms < end_ms)
		;
	info->time_elapsed = start_ms + end_ms;
	return (info->time_elapsed);
}
