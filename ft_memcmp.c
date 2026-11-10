/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:32:24 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:33:46 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	unsigned int	i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (ptr_s1[i] == ptr_s2[i] && i < n - 1)
		i++;
	return (ptr_s1[i] - ptr_s2[i]);
}
