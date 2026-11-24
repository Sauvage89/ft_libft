/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:34:56 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/24 15:34:57 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	len_src = 0;
	while (src[len_src])
		len_src++;
	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (len_dst == size)
		return (len_src + len_dst);
	i = 0;
	while (src[i] && i < size - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_try_cpy;
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	len_try_cpy = 0;
	while (src[len_try_cpy])
		len_try_cpy++;
	if (size == 0)
		return (len_try_cpy);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len_try_cpy);
}
