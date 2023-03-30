/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:22 by tnam              #+#    #+#             */
/*   Updated: 2023/03/30 19:08:57 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	printf("%ldms %ld is thinking\n",
		ft_current_time(philo->info), philo->philo_id);
	return (SUCCESS);
}
