/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:25:27 by tnam              #+#    #+#             */
/*   Updated: 2023/04/12 14:26:05 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_check_die(t_philo *philo)
{
	if (ft_current_time(philo) - philo->last_eat_time >= philo->time_to_die)
		exit(philo->philo_id);
}
