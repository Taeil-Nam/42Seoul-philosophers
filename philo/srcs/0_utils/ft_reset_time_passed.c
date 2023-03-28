/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_time_passed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/28 11:57:30 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_reset_time_passed(t_info *info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - info->time_booted);
}
