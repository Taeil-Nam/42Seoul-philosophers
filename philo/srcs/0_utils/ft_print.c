/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:22:31 by tnam              #+#    #+#             */
/*   Updated: 2023/05/08 20:27:18 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_info *info, long id, char *msg)
{
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %ld %s", ft_current_time(info), id, msg);
	pthread_mutex_unlock(&(info->print_mutex));
}
