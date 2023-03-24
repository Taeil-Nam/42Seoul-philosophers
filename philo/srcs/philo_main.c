/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/24 19:36:04 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info			info;
	static t_philo	**philos;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	ft_init_info(argc, argv, &info);
	ft_init_philo(&info, philos);
	/* 1. eat */
	/* 2. sleep */
	/* 3. think */
	return (0);
}
