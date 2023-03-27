/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/28 00:14:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time_init(t_info *info)
{
	struct timeval	temp_time;
	
	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	return (SUCCESS);
}