/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/04/13 16:10:49 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_getlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long n)
{
	int			len;
	char		*result;

	len = ft_getlen(n);
	result = malloc((len * sizeof(char)) + 1);
	if (result == 0)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result[0] = '0';
	result[len] = 0;
	len--;
	while (n != 0)
	{
		result[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (result);
}
