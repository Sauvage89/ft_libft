/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:13:15 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/05 14:40:52 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_src + n > ptr_dest)
		ft_memmove((void *)ptr_dest, (void *)ptr_src, n);
	else
	{
		while (n < 0)
		{
			ptr_dest[n] = ptr_src[n];
			n--;
		}
	}
	return (ptr_dest);
}
