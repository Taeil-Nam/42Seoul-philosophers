/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_time_passed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/27 23:40:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_reset_time_passed(t_info *info)
{
    struct timeval  tv;
    
    if (gettimeofday(&tv, NULL) == -1)
        return (FAILURE);
    return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - info->time_booted);
}
