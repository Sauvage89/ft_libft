/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:38:58 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/12 13:15:38 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char			*new;
	unsigned int	i;

	if (s == 0)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new == 0)
		return (0);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i] = 0;
	return (new);
}
