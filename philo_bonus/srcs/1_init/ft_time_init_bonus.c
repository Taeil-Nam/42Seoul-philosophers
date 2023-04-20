/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:13:28 by tnam              #+#    #+#             */
/*   Updated: 2023/04/20 11:13:30 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_time_init(t_philo *philo)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	philo->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	return (SUCCESS);
}
