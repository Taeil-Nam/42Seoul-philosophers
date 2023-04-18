/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:43:06 by tnam              #+#    #+#             */
/*   Updated: 2023/04/06 15:02:43 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*ft_monitoring_thread(void *philo_v)
{
	t_philo	*philo;

	philo = (t_philo *)philo_v;
	while (TRUE)
	{
		usleep(300);
		sem_wait(philo->lock_philo);
		if (ft_current_time(philo) - philo->last_eat_time >= philo->time_to_die)
		{
			sem_close(philo->lock_philo);
			free(philo->lock_philo_id);
			exit(philo->philo_id);
		}
		sem_post(philo->lock_philo);
		if (philo->eat_count >= philo->must_eat_count
			&& philo->must_eat_count != 0)
		{
			sem_close(philo->lock_philo);
			free(philo->lock_philo_id);
			exit(FINISH_EAT);
		}
	}
}

void	ft_child_routine(t_philo *philo)
{
	pthread_t	monitoring_thread;

	free(philo->child);
	philo->lock_philo_id = ft_ltoa(philo->philo_id);
	sem_unlink(philo->lock_philo_id);
	philo->lock_philo = sem_open(philo->lock_philo_id, O_CREAT | O_EXCL, 0, 1);
	if (philo->lock_philo == SEM_FAILED)
	{
		printf("philo%ld: sem_open() failed.\n", philo->philo_id);
		exit(philo->philo_id);
	}
	philo->last_eat_time = ft_current_time(philo);
	if (philo->philo_id % 2 == 1)
		usleep(philo->time_to_die / 4 * 1000);
	pthread_create(&monitoring_thread, NULL, ft_monitoring_thread, philo);
	pthread_detach(monitoring_thread);
	while (TRUE)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
