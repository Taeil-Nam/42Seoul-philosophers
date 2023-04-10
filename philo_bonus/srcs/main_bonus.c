/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/04/10 10:21:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_info_init(argc, argv, &info) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	if (ft_time_init(&info) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));
	
	sem_t	*fork_holder;

	pid_t	*philo_pid;
	philo_pid = (pid_t *)calloc(sizeof(pid_t) * (info.num_of_philo + 2), 1);
	sem_unlink("/fork_holder");
	fork_holder = sem_open("/fork_holder", O_CREAT | O_EXCL, 0, 5);

	t_philo	philo;

	long	philo_id = 1;
	while (philo_id <= info.num_of_philo)
	{
		philo.philo_id = philo_id;
		philo.info = &info;
		philo.left_fork_up = FALSE;
		philo.right_fork_up = FALSE;
		philo.last_eat_time = ft_current_time(&info);
		philo.eat_count = 0;
		philo_pid[philo_id] = fork();
		if (philo_pid[philo_id] == 0)
		{
			child_function();
		}
	}
	philo_id = 1;
	while (philo_id <= info.num_of_philo)
	{
		waitpid(philo_pid[philo_id], NULL, 0);
		philo_id++;
	}

	sem_close(fork_holder);
	sem_unlink("/frok_holder");

	return (EXIT_SUCCESS);
}
