/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:13:24 by tnam              #+#    #+#             */
/*   Updated: 2023/05/15 15:06:09 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sem_init(t_philo *philo)
{
	sem_unlink("/fork_holder");
	philo->fork_holder
		= sem_open("/fork_holder", O_CREAT | O_EXCL, 0, philo->num_of_philo);
	if (philo->fork_holder == SEM_FAILED)
		return (FAILURE);
	sem_unlink("/print");
	philo->print
		= sem_open("/print", O_CREAT | O_EXCL, 0, 1);
	if (philo->print == SEM_FAILED)
		return (FAILURE);
	return (SUCCESS);
}
