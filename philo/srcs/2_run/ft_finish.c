/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:03 by tnam              #+#    #+#             */
/*   Updated: 2023/05/08 20:22:18 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->finish_eat_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
	ft_free_forks(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
	free(info->eat_enough);
}
