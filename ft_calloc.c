/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:46:28 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 08:56:01 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*new;
	unsigned int	i;
	unsigned int	j;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
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
