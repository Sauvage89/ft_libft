/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:20:18 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 08:14:28 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
