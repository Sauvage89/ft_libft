/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:07:10 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/09 23:02:13 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	len_nb(int nb)
{
	unsigned int	count;

	count = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (ft_strlen("-2147483648"));
		nb *= -1;
		count++;
	}
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	count++;
	return (count);
}

static int	is_negatif(char *str, int *n, unsigned int *c_sign)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			ft_strlcpy(str, "-2147483648", ft_strlen("-2147483648") + 1);
			return (1);
		}
		*c_sign = 1;
		str[0] = '-';
		*n *= -1;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	count;
	unsigned int	count_sign;

	count = len_nb(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (0);
	count_sign = 0;
	if (is_negatif(str, &n, &count_sign) == 1)
		return (str);
	str[count] = 0;
	while (count > count_sign)
	{
		count--;
		str[count] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
