/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/05 19:55:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->mutex));
	ft_free_forks(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
}
