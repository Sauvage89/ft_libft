/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:26:09 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/24 15:27:57 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		s = (char *)s + 1;
		n--;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((char *)s1)[i] == ((char *)s2)[i] && i < n - 1)
		i++;
	return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == 0 && src == 0)
		return (0);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		((char *)dest)[n] = ((char *)src)[n];
		if (n == 0)
			break ;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
