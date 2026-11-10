/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:25:09 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:38:29 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, (char)s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
