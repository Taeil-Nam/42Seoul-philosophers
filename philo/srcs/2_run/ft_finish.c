/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/06 16:38:06 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->finish_eat_mutex));
	ft_free_forks(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
	free(info->eat_enough);
}
