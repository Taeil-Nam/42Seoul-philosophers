/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:54:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/10 14:01:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sem_init(t_philo *philo)
{
	sem_unlink("/fork_holder");
	philo->fork_holder
		= sem_open("/fork_holder", O_CREAT | O_EXCL, 0, philo->num_of_philo);
	sem_unlink("/end_alert");
	philo->end_alert
		= sem_open("/end_alert", O_CREAT | O_EXCL, 0, 1);
	if (philo->fork_holder == SEM_FAILED || philo->end_alert == SEM_FAILED)
		return (FAILURE);
	return (SUCCESS);
}
