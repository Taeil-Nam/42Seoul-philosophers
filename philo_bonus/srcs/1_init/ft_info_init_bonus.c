/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:33 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/10 14:02:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philo_init(int argc, char *argv[], t_philo *philo)
{
	philo->argc = argc;
	philo->argv = argv;
	philo->num_of_philo = ft_atol(argv[1]);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	philo->fork_taking = 0;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	if (argc == 5)
		philo->must_eat_count = 0;
	else if (argc == 6)
		philo->must_eat_count = ft_atol(argv[5]);
	if (philo->num_of_philo <= 0 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0
		|| philo->must_eat_count < 0
		|| (philo->argc == 6 && philo->must_eat_count == 0))
		return (FAILURE);
	return (SUCCESS);
}
