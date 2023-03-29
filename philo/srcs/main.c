/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/29 11:37:12 by tnam             ###   ########.fr       */
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
	if (ft_fork_init(&info) == FAILURE)
		return (ft_error("fork_init() returns FAILURE", EXIT_FAILURE));
	if (ft_philo_init(&info) == FAILURE)
		return (ft_error("philo_init() returns FAILURE", EXIT_FAILURE));
	if (ft_time_init(&info) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));

	/* 철학자, 포크간 연동 테스트 */
	for (int i = 0; i < info.num_of_philo; i++)
	{
		printf("philo id : %ld, left fork id : %ld, right fork id : %ld\n",
			info.philos[i]->philo_id,
			info.philos[i]->left_fork->fork_id,
			info.philos[i]->right_fork->fork_id);
	}

	//메인 파트
	if (ft_start_logic(&info, (info.philos)) == FAILURE)
		return (ft_error("execute_logic() returns FAILURE", EXIT_FAILURE));


	//종료 파트
	return (EXIT_SUCCESS);
}
