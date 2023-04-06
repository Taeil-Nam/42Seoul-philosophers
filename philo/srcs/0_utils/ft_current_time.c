/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:55 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 15:30:25 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_current_time(t_info *info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - info->time_booted);
}
