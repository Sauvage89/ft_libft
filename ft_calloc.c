/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:46:28 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:32:15 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void			*new;
	unsigned int	i;
	unsigned int	j;

	new = (void *)malloc(size * nmemb);
	if (new == 0)
		return (0);
	i = 0;
	while (i < nmemb)
	{
		j = 0;
		while (j < size)
		{
			((char *)new)[(i * size) + j] = 0;
			j++;
		}
		i++;
	}
	return (new);
}
