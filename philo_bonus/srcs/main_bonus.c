/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:22:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/10 15:12:16 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;
	pid_t	*child;
	long	index;
	int		child_return;
	if (!(argc == 5 || argc == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_philo_init(argc, argv, &philo) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	if (ft_sem_init(&philo) == FAILURE)
		return (ft_error("sem_open returns -1(error)", EXIT_FAILURE));
	if (ft_time_init(&philo) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));

	child = (pid_t *)malloc(sizeof(pid_t) * philo.num_of_philo);
	//if (child == NULL)
	//	return (ft_error("malloc error", EXIT_FAILURE));

	/* 자식 프로세스 생성 */
	index = 0;
	while (index < philo.num_of_philo)
	{
		philo.philo_id = index + 1;
		child[index] = fork();
		if (child[index] == 0)
			ft_child_routine(&philo);
		index++;
	}

	/* 생성된 자식 프로세스들 wait */
	index = 0;
	while (index < philo.num_of_philo)
	{
		waitpid(-1, &child_return, 0);
		if (child_return == STARVED)
		{
			while (index < philo.num_of_philo)
				kill(child[index++], SIGINT);
			free(child);
			return (EXIT_SUCCESS);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}
