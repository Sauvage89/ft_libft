/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:20:18 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/09 22:31:54 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (dest == 0 && src == 0)
		return (0);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_src > ptr_dest)
		return (ft_memcpy((void *)ptr_dest, (void *)ptr_src, n));
	while (n > 0)
	{
		n--;
		ptr_dest[n] = ptr_src[n];
		if (n == 0)
			break ;
	}
	return (ptr_dest);
}
