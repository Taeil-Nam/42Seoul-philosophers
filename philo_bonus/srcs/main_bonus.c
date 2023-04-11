/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:22:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/11 20:34:10 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_create_child(t_philo *philo)
{
	long	index;

	index = 0;
	while (index < philo->num_of_philo)
	{
		philo->philo_id = index + 1;
		philo->child[index] = fork();
		if (philo->child[index] == 0)
			ft_child_routine(philo);
		index++;
	}
}

static void	ft_wait_child(t_philo *philo)
{
	long	index;
	int		child_status;
	int		child_exit_code;

	index = 0;
	while (index < philo->num_of_philo)
	{
		waitpid(-1, &child_status, 0);
		child_exit_code = WEXITSTATUS(child_status);
		if (child_exit_code != FINISH_EAT)
		{
			index = 0;
			while (index < philo->num_of_philo)
			{
				kill(philo->child[index], SIGINT);
				index++;
			}
			printf("%ld %d died\n", ft_current_time(philo), child_exit_code);
			return ;
		}
		index++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if (!(argc == 5 || argc == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_philo_init(argc, argv, &philo) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	if (ft_sem_init(&philo) == FAILURE)
		return (ft_error("sem_open returns -1(error)", EXIT_FAILURE));
	if (ft_time_init(&philo) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));
	philo.child = (pid_t *)malloc(sizeof(pid_t) * philo.num_of_philo);
	if (philo.child == NULL)
		return (ft_error("malloc error", EXIT_FAILURE));
	ft_create_child(&philo);
	ft_wait_child(&philo);
	free(philo.child);
	sem_close(philo.fork_holder);
	return (EXIT_SUCCESS);
}
