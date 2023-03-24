/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/24 20:37:10 by tnam             ###   ########.fr       */
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
	
	/* philo 생성 부분 */
	philos = (t_philo **)malloc(sizeof(t_philo *) * (info.num_of_philo + 1));
	if (philos == NULL)
		return (FAILURE);
	if (ft_philo_init(&info, philos) == FAILURE)
		return (ft_error("philo_init() returns FAILURE", EXIT_FAILURE));
	
	//메인 파트
	printf("test\n");
	for (int i = 0; i < info.num_of_philo; i++)
		printf("%ld ", philos[i]->philo_num);
	printf("\n");
	for (int i = 0; i < info.num_of_philo; i++)
		printf("%ld ", philos[i]->fork_count);


	//종료 파트
	return (EXIT_SUCCESS);
}
