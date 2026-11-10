/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:24:13 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:27:27 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_reset(char **splits, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

static unsigned int	len_first_elem(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			break ;
		count++;
	}
	return (count);
}

static int	save_copy(char **splits, const char *s, char c, unsigned int len)
{
	unsigned int	len_elem;

	len_elem = len_first_elem(s, c);
	if (len_elem == 0)
	{
		ft_reset(splits, len);
		return (-1);
	}
	*splits = ft_substr((char *)s, 0, len_elem);
	if (*splits == 0)
	{
		ft_reset(splits, len);
		return (-1);
	}
	return (0);
}

static unsigned int	nb_splited_elem(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**splits;
	unsigned int	len;
	unsigned int	i;

	len = nb_splited_elem(s, c);
	splits = (char **)malloc((sizeof(char *) * (len + 1)));
	if (splits == 0)
		return (0);
	i = 0;
	splits[len] = 0;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (save_copy(splits + i, s, c, len) == -1)
				return (0);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (splits);
}
