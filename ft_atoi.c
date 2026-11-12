/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:46:41 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/12 13:22:35 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

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
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (nb * 10 + nptr[i] - '0' < nb && sign == 1)
			return (-1);
		if (nb * 10 + nptr[i] - '0' < nb * sign && sign == -1)
			return (0);
		nb = nb * 10 + nptr[i++] - '0';
	}
	return (nb * sign);
}
