/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 00:18:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	
	//초기화 파트
	if (!(argc == 5 || argc == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_argv_init(argc, argv, &info) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	if (ft_philo_init(&info) == FAILURE)
		return (ft_error("philo_init() returns FAILURE", EXIT_FAILURE));
	if (ft_time_init(&info) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));

	//메인 파트
	if (ft_execute_logic(&info, (info.philos)) == FAILURE)
		return (ft_error("execute_logic() returns FAILURE", EXIT_FAILURE));
	sleep(1);
	printf("passed time : %ld\n", ft_reset_time_passed(&info));
	//종료 파트
	return (EXIT_SUCCESS);
}
