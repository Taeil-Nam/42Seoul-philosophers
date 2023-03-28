/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/28 14:31:34 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time_init(t_info *info)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	info->time_elapsed = 0;
	return (SUCCESS);
}
