/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:33:20 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/11 18:29:22 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) - start > ft_strlen(s))
		len = 0;
	else if ((unsigned int)ft_strlen(s) <= start + len)
		len = (unsigned int)ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len && s[i] && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
