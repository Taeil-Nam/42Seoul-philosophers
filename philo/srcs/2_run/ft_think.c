/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:26 by tnam              #+#    #+#             */
/*   Updated: 2023/04/20 11:12:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_check_died(philo->info, philo) == TRUE)
		return (FAILURE);
	printf("%ld %ld is thinking\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}
