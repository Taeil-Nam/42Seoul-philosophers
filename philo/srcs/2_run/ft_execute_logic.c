/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:33:08 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 00:15:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int g_num = 0; /* test용 전역 변수(삭제 필요) */

/* test용 함수(삭제 필요) */
static void	*test(void *philo)
{
	for (int i = 0; i < 50000; i++)
	{
		if (((t_philo *)philo)->philo_num % 2 == 0)
			 g_num++;
		else
			 g_num--;
	}
	printf("%d\n",  g_num); // 전역 변수  g_num의 값 출력
	return (SUCCESS);
}

static int	ft_create_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_create(&philos[philo_count]->thread, NULL, test,
				philos[philo_count]) != 0)
		{
			ft_free_philos(philos, info->num_of_philo);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

static int	ft_join_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_join(philos[philo_count]->thread, NULL) != 0)
		{
			ft_free_philos(philos, info->num_of_philo);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

int	ft_execute_logic(t_info *info, t_philo **philos)
{
	if (ft_create_thread(info, philos) == FAILURE)
		return (FAILURE);
	if (ft_join_thread(info, philos) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
