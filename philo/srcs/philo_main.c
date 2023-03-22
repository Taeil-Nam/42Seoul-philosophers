/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/22 20:32:52 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	args;

	if (argc == 5)
	{
		args.num_of_philo = ft_atol(argv[1]);
		args.time_to_die = ft_atol(argv[2]);
		args.time_to_eat = ft_atol(argv[3]);
		args.time_to_sleep = ft_atol(argv[4]);
		printf("%ld, %ld, %ld, %ld", args.num_of_philo, args.time_to_die,
			args.time_to_eat, args.time_to_sleep);
	}
	else if (argc == 6)
	{
		args.num_of_philo = ft_atol(argv[1]);
		args.time_to_die = ft_atol(argv[2]);
		args.time_to_eat = ft_atol(argv[3]);
		args.time_to_sleep = ft_atol(argv[4]);
		args.must_eat_count = ft_atol(argv[5]);
		printf("%ld, %ld, %ld, %ld, %ld", args.num_of_philo, args.time_to_die,
			args.time_to_eat, args.time_to_sleep, args.must_eat_count);
	}
	else
		return (EXIT_FAILURE);
	return (0);
}
