/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:22 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 23:17:30 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_is_died(philo->info, philo) == TRUE
		|| ft_is_other_died(philo->info) == TRUE)
		return (FAILURE);
	printf("%ldms %ld is thinking\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}
