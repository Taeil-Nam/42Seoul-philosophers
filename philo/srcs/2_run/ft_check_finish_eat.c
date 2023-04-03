/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:41 by tnam              #+#    #+#             */
/*   Updated: 2023/04/03 20:08:03 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_finish_eat(t_philo *philo)
{
	if (philo->info->must_eat_count > 0
		&& philo->info->must_eat_count <= philo->eat_count)
	{
		philo->info->finish_eat_flag = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
