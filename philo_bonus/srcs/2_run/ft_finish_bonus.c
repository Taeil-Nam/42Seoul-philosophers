/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/06 16:40:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->mutex));
	ft_free_forks(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
}
