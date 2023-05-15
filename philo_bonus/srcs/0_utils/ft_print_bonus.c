/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:22:31 by tnam              #+#    #+#             */
/*   Updated: 2023/05/15 15:07:05 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philo *philo, long id, char *msg)
{
	sem_wait(philo->print);
	printf("%ld %ld %s", ft_current_time(philo), id, msg);
	sem_post(philo->print);
}
