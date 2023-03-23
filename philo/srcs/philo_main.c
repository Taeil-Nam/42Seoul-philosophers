/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/23 17:30:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static void	ft_init_info(int argc, char *argv[], t_info *info)
{
	info->argc = argc;
	info->argv = argv;
	if (argc == 5)
	{
		info->num_of_philo = ft_atol(argv[1]);
		info->time_to_die = ft_atol(argv[2]);
		info->time_to_eat = ft_atol(argv[3]);
		info->time_to_sleep = ft_atol(argv[4]);
		info->must_eat_count = 0;
	}
	else if (argc == 6)
	{
		info->num_of_philo = ft_atol(argv[1]);
		info->time_to_die = ft_atol(argv[2]);
		info->time_to_eat = ft_atol(argv[3]);
		info->time_to_sleep = ft_atol(argv[4]);
		info->must_eat_count = ft_atol(argv[5]);
	}
	if (info->num_of_philo < 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0
		|| info->must_eat_count < 0)
		ft_error("negative arg(s) found.");
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	ft_init_info(argc, argv, &info);
	return (0);
}
