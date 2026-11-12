/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:55:20 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/11 18:31:28 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	unsigned int	i;
	unsigned int	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (join == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}
