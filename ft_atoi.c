/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:46:41 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/13 10:46:15 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign = 44 - nptr[i++];
	while (ft_isdigit(nptr[i]))
	{
		if (nb * 10 + nptr[i] - '0' < nb && sign == 1)
			return (-1);
		if (nb * 10 + nptr[i] - '0' < nb - 1 && sign == -1)
			return (0);
		nb = nb * 10 + nptr[i++] - '0';
	}
	return (nb * sign);
}
/*
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	long long	i;
	char		str[512];

	
	// overflow && underflow
	i = LLONG_MAX - 15;
	printf("overflow and underflow limit case\n");
	printf("max case 9223372036854775808\nmin case -9223372036854775809\n");
	while (i != LLONG_MIN + 15)
	{
		ft_bzero((void *)str, 32);
		sprintf(str, "%lli", i);
		if (str[ft_strlen(str) - 1] < '9')
			str[ft_strlen(str) - 1] += 1;
		if (ft_atoi(str) != atoi(str))
		{
			printf("error on %lli\n", i);
			return (0);
		}
		printf("str is %s lli is %lli result is %i\n", str, i, atoi(str));
		i++;
	}

	// normal
	printf("normal lli limit case\n");
	i = LLONG_MAX - 15;
	while (i != LLONG_MIN + 15)
	{
		ft_bzero((void *)str, 32);
		sprintf(str, "%lli", i);
		if (ft_atoi(str) != atoi(str))
		{
			printf("error on %lli\n", i);
			return (0);
		}
		printf("str is %s lli is %lli result is %i\n", str, i, atoi(str));
		i++;
	}
	printf("normal int limit case\n");
	i = INT_MAX - 15;
	while ((int)i != -2147483634)
	{
		ft_bzero((void *)str, 32);
		sprintf(str, "%lli", i);
		if (ft_atoi(str) != atoi(str))
		{
			printf("error on %lli\n", i);
			return (0);
		}
		printf("str is %s lli is %lli result is %i\n", str, i, atoi(str));
		i++;
	}
	printf("normal int case\n");
	i = 0;
	while (i != 127)
	{
		ft_bzero((void *)str, 32);
		sprintf(str, "%lli", i);
		if (ft_atoi(str) != atoi(str))
		{
			printf("error on %lli\n", i);
			return (0);
		}
		printf("str is %s lli is %lli result is %i\n", str, i, atoi(str));
		i++;
	}

}*/
