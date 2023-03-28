/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elapsed_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:55 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 14:51:39 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_current_time(t_info *info)
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
