/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 14:50:48 by tnam             ###   ########.fr       */
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

	printf("elapsed time : %ldms\n",
		ft_elapsed_time(info.time_elapsed, info.time_to_die, &info));
	printf("elapsed time : %ldms\n",
		ft_elapsed_time(info.time_elapsed, info.time_to_die, &info));

	//종료 파트
	return (EXIT_SUCCESS);
}
