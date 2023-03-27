/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/27 22:09:27 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	**philos;

	//초기화 파트
	if (!(argc == 5 || argc == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_argv_init(argc, argv, &info) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	philos = (t_philo **)malloc(sizeof(t_philo *) * (info.num_of_philo + 1));
	if (philos == NULL)
		return (FAILURE);
	if (ft_philo_init(&info, philos) == FAILURE)
		return (ft_error("philo_init() returns FAILURE", EXIT_FAILURE));

	//메인 파트
	if (ft_execute_logic(&info, philos) == FAILURE)
		return (ft_error("execute_logic() returns FAILURE", EXIT_FAILURE));

	//종료 파트
	return (EXIT_SUCCESS);
}
