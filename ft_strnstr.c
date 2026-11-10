/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:38:17 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:36:01 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
