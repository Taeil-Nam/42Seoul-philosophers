/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:02:53 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/21 16:36:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>

#include <stdio.h>

typedef struct s_strtol
{
	const char		*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				neg;
	int				any;
	int				cutlim;
}	t_strtol;

int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || 
			c == '\v' || c == '\f' || c == '\r');
}

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_strtol	v;
	int c;
	const char *s;

	s = nptr;
	v.neg = 0;
	while (ft_isspace(*s))
		s++;
	c = *s++;
	if (c == '-')
	{
		v.neg = 1;
		c = *s++;
	}
	else if (c == '+')
		c = *s++;
	
	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
	{
		c = s[1];
		s += 2;
		base = 16;
	}
	else if ((base == 0 || base == 2) && c == '0' && (*s == 'b' || *s == 'B'))
	{
		c = s[1];
		s += 2;
		base = 2;
	}
	if (base == 0)
	{
		if (c == '0') {
			base = 8;
		} else {
			base = 10;
		}
	}
	if (v.neg)
		v.cutoff = -(unsigned long)LONG_MIN;
	else
		v.cutoff = LONG_MAX;
	v.cutlim = v.cutoff % (unsigned long)base;
	v.cutoff /= (unsigned long)base;
	v.acc = 0;
	v.any = 0;
	while (1)
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
		{
			if (ft_isupper(c))
				c -= 'A' - 10;
			else
				c -= 'a' - 10;
		}
		else
			break;
		if (c >= base)
			break;
		if (v.any < 0 || v.acc > v.cutoff || (v.acc == v.cutoff && c > v.cutlim))
			v.any = -1;
		else
		{
			v.any = 1;
			v.acc *= base;
			v.acc += c;
		}
		c = *s++;
	}
	if (v.any < 0)
	{
		if (v.neg)
			v.acc = LONG_MIN;
		else
			v.acc = LONG_MAX;
	} 
	else if (v.neg)
		v.acc = -v.acc;
	if (endptr != 0)
	{
		if (v.any)
			*endptr = (char *)(s - 1);
		else
			*endptr = (char *)nptr;
	}
	return (v.acc);
}

long	ft_atol(const char *str)
{
	return(ft_strtol(str, (char **)NULL, 10));
}

int main ()
{
	printf("%ld\n", ft_atol("     -123456789122412\n"));

	//printf("%ld\n", atol("    -12345678912\n"));
}