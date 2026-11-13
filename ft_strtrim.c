/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:25:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/13 12:51:05 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (0);
		set++;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (is_sep(s1[start], set) == 0)
		start++;
	i = start;
	while (s1[i])
	{
		while (s1[i] && is_sep(s1[i], set) == -1)
			i++;
		j = i;
		while (s1[j] && is_sep(s1[j], set) == 0)
			j++;
		if (s1[j] == 0)
			break ;
		i = j;
	}
	return (ft_substr(s1, start, i - start));
}
